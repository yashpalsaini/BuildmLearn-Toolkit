/*
  Copyright (c) 2012, BuildmLearn Contributors listed at http://buildmlearn.org/people/
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the name of the BuildmLearn nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "templates/dictation/dictationeditor.h"

#include "miscellaneous/iconfactory.h"
#include "templates/dictation/dictationpassage.h"
#include "core/templatefactory.h"
#include "core/templatecore.h"
#include "core/templateentrypoint.h"

#include <QToolTip>
#include <QTimer>
#include <QShowEvent>
#include <QDomDocument>
#include <QDomElement>
#include <QDomAttr>


DictationEditor::DictationEditor(TemplateCore *core, QWidget *parent)
  : TemplateEditor(core, parent), m_ui(new Ui::DictationEditor) {
  m_ui->setupUi(this);

  // Set validators.
  QRegExpValidator *author_validator = new QRegExpValidator(this);
  QRegExpValidator *title_validator = new QRegExpValidator(this);


  author_validator->setRegExp(QRegExp(".{,50}"));
  title_validator->setRegExp(QRegExp(".{,100}"));

  m_ui->m_txtAuthor->lineEdit()->setValidator(author_validator);
  m_ui->m_txtName->lineEdit()->setValidator(title_validator);
  m_ui->m_txtPassage->setMaxLength(2500);
  

  m_ui->m_txtAuthor->lineEdit()->setPlaceholderText(tr("Author of this test"));
  m_ui->m_txtName->lineEdit()->setPlaceholderText(tr("Name of this test"));

  
  m_ui->m_btnPassageAdd->setIcon(factory->fromTheme("item-add"));
  m_ui->m_btnPassageRemove->setIcon(factory->fromTheme("item-remove"));


  connect(m_ui->m_txtAuthor->lineEdit(), SIGNAL(textChanged(QString)), this, SLOT(updateAuthorStatus()));
  connect(m_ui->m_txtName->lineEdit(), SIGNAL(textChanged(QString)), this, SLOT(updateNameStatus()));

  connect(m_ui->m_btnPassageAdd, SIGNAL(clicked()), this, SLOT(addPassage()));
  connect(m_ui->m_btnPassageRemove, SIGNAL(clicked()), this, SLOT(removePassage()));
 
  connect(m_ui->m_txtPassage, SIGNAL(textChanged()), this, SLOT(savePassage()));

  setEditorEnabled(true);
  checkName();
  checkAuthor();
  qRegisterMetaType<DictationPassage>("DictationPassage"); 
}

DictationEditor::~DictationEditor() {
  qDebug("Destroying DictationEditor instance.");

  delete m_ui;
}

QString DictationEditor::projectName() {
  return m_ui->m_txtName->lineEdit()->text();
}

QString DictationEditor::authorName() {
  return m_ui->m_txtAuthor->lineEdit()->text();
}


void DictationEditor::addPassage(const QString &passage) {
  DictationPassage new_passage;
  new_passage.setPassage(passage);
 
  int marked_question = m_ui->m_listPassage->currentRow();
  QListWidgetItem *new_item = new QListWidgetItem();
  new_item->setText(new_passage.passage());
  m_ui->m_listPassage->insertItem(0, new_item);
}

  launch();     
  emit changed(); 
}

DictationPassage DictationEditor::activePassage() const {
  DictationPassage passage;
    passage.append(m_ui->m_listPassage->item(0)->data(Qt::UserRole).value<DictationPassage>());
  return passage;
}

void DictationEditor::removePassage() {
   int current_row = m_ui->m_listPassage->currentRow();
   m_ui->m_btnPassageRemove->setEnabled(false);
   delete m_ui->m_listPassage->takeItem(current_row);
  }

  launch();  
  emit changed(); 
}

void DictationEditor::savePassage() {
  m_activePassage.setPassage(m_ui->m_txtQuestion->toPlainText());
  m_ui->m_listPassage->currentItem()->setText(m_activePassage.passage());
  emit changed();   
}

void DictationEditor::setEditorEnabled(bool enabled) {
  m_ui->m_groupPassageEditor->setEnabled(enabled);
}

void DictationEditor::checkName() {
  if (m_ui->m_txtName->lineEdit()->text().simplified().isEmpty()) {
    m_ui->m_txtName->setStatus(WidgetWithStatus::Error, tr("Enter the name of the test."));
  }
  else {
    m_ui->m_txtName->setStatus(WidgetWithStatus::Ok, tr("Name is okay."));
  }
}

void DictationEditor::checkAuthor() {
  if (m_ui->m_txtAuthor->lineEdit()->text().simplified().isEmpty()) {
    m_ui->m_txtAuthor->setStatus(WidgetWithStatus::Error, tr("Enter the name of the author of the test."));
  }
  else {
    m_ui->m_txtAuthor->setStatus(WidgetWithStatus::Ok, tr("Enter the name of the author of the test."));
  }
}

void DictationEditor::updateNameStatus() {
  checkName();
  launch();
  emit changed();
}

void DictationEditor::updateAuthorStatus() {
  checkAuthor();
  launch();
  emit changed(); 
}

bool DictationEditor::canGenerateApplications() {
  return
      !m_ui->m_txtName->lineEdit()->text().simplified().isEmpty() &&
      !m_ui->m_txtAuthor->lineEdit()->text().simplified().isEmpty() &&
    // checking that passage is present or not 
      !activePassage().isEmpty();
}

bool DictationEditor::loadBundleData(const QString &bundle_data) {
  QDomDocument bundle_document;
  bundle_document.setContent(bundle_data);

  QDomNodeList items = bundle_document.documentElement().elementsByTagName("item");

  for (int i = 0; i < items.size(); i++) {
    QDomNode item = items.at(0);

    if (item.isElement()) {
      QString passage = item.namedItem("passage").toElement().text();
   
      if (passage.isEmpty()) {
        // TODO: error
        continue;
      }
      else {
        addPassage(passage);
      }
    }
    else {
      continue;
    }
  }

  // Load author & name.
  m_ui->m_txtAuthor->lineEdit()->setText(bundle_document.documentElement().namedItem("author").namedItem("name").toElement().text());
  m_ui->m_txtName->lineEdit()->setText(bundle_document.documentElement().namedItem("title").toElement().text());

  return true;
}

QString DictationEditor::generateBundleData() {
  /*if (!canGenerateApplications()) {
    return QString();
  }*/

  QDomDocument source_document = qApp->templateManager()->generateBundleHeader(core()->entryPoint()->typeIndentifier(),
                                                                               m_ui->m_txtAuthor->lineEdit()->text(),
                                                                               QString(),
                                                                               m_ui->m_txtName->lineEdit()->text(),
                                                                               QString(),
                                                                               "1");
  FIND_DATA_ELEMENT(data_element, source_document);

    DictationPassage passage = activePassage();
    QDomElement item_element = source_document.createElement("item");
    QDomElement passage_element = source_document.createElement("passage")  
    passage_element.appendChild(source_document.createTextNode(passage.passage()));
    item_element.appendChild(passage_element);
    data_element.appendChild(item_element);
  
  return source_document.toString(XML_BUNDLE_INDENTATION);
}
