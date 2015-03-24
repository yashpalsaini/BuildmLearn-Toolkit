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

#include "templates/matchthefollowing/matchthefollowingeditor.h"

#include "miscellaneous/iconfactory.h"
#include "templates/matchthefollowing/matchthefollowingtopic.h"
#include "core/templatefactory.h"
#include "core/templatecore.h"
#include "core/templateentrypoint.h"

#include <QToolTip>
#include <QTimer>
#include <QShowEvent>
#include <QDomDocument>
#include <QDomElement>
#include <QDomAttr>


MatchEditor::MatchEditor(TemplateCore *core, QWidget *parent)
  : TemplateEditor(core, parent), m_ui(new Ui::MatchEditor) {
  m_ui->setupUi(this);

  // Set validators.
  QRegExpValidator *author_validator = new QRegExpValidator(this);
  QRegExpValidator *title_validator = new QRegExpValidator(this);

  author_validator->setRegExp(QRegExp(".{,50}"));
  title_validator->setRegExp(QRegExp(".{,100}"));

  m_ui->m_txtAuthor->lineEdit()->setValidator(author_validator);
  m_ui->m_txtName->lineEdit()->setValidator(title_validator);
  m_ui->m_txtTopicSet1->setMaxLength(160);
  m_ui->m_txtTopicSet2->setMaxLenght(160);


  m_ui->m_txtNumberOfTopics->lineEdit()->setEnabled(false);
  
  m_ui->m_txtAuthor->lineEdit()->setPlaceholderText(tr("Author of this test"));
  m_ui->m_txtName->lineEdit()->setPlaceholderText(tr("Name of this test"));


  m_ui->m_btnTopicSet1Add->setIcon(factory->fromTheme("item-add"));
  m_ui->m_btnTopicSet1Remove->setIcon(factory->fromTheme("item-remove"));
  m_ui->m_btnTopicSet1Up->setIcon(factory->fromTheme("move-up"));
  m_ui->m_btnTopicSet1Down->setIcon(factory->fromTheme("move-down"));
  m_ui->m_btnTopicSet2Add->setIcon(factory->fromTheme("item-add"));
  m_ui->m_btnTopicSet2Remove->setIcon(factory->fromTheme("item-remove"));
  m_ui->m_btnTopicSet2Up->setIcon(factory->fromTheme("move-up"));
  m_ui->m_btnTopicSet2Down->setIcon(factory->fromTheme("move-down"));

  m_iconNo = factory->fromTheme("dialog-no");
  m_iconYes = factory->fromTheme("dialog-yes");

  
  connect(m_ui->m_txtAuthor->lineEdit(), SIGNAL(textChanged(QString)), this, SLOT(updateAuthorStatus()));
  connect(m_ui->m_txtName->lineEdit(), SIGNAL(textChanged(QString)), this, SLOT(updateNameStatus()));

  connect(m_ui->m_btnTopicSet1Add, SIGNAL(clicked()), this, SLOT(addTopicSet1()));
  connect(m_ui->m_btnTopicSet1Remove, SIGNAL(clicked()), this, SLOT(removeTopicSet1()));
  connect(m_ui->m_listTopicsSet1, SIGNAL(currentRowChanged(int)), this, SLOT(loadTopicSet1(int)));
  
  connect(m_ui->m_txtTopicSet1Answer, SIGNAL(textEdited(QString)), this, SLOT(saveTopicSet1()));
  connect(m_ui->m_txtTopicSet1, SIGNAL(textChanged()), this, SLOT(saveTopicSet1()));

  connect(m_ui->m_btnTopicSet1Up, SIGNAL(clicked()), this, SLOT(moveTopicSet1Up()));
  connect(m_ui->m_btnTopicSet1Down, SIGNAL(clicked()), this, SLOT(moveTopicSet1Down()));
  
  
  connect(m_ui->m_btnTopicSet2Add, SIGNAL(clicked()), this, SLOT(addTopicSet2()));
  connect(m_ui->m_btnTopicSet2Remove, SIGNAL(clicked()), this, SLOT(removeTopicSet2()));
  connect(m_ui->m_listTopicsSet2, SIGNAL(currentRowChanged(int)), this, SLOT(loadTopicSet2(int)));
  
  connect(m_ui->m_txtTopicSet2Answer, SIGNAL(textEdited(QString)), this, SLOT(saveTopicSet2()));
  connect(m_ui->m_txtTopicSet2, SIGNAL(textChanged()), this, SLOT(saveTopicSet2()));

  connect(m_ui->m_btnTopicSet2Up, SIGNAL(clicked()), this, SLOT(moveTopicSet2Up()));
  connect(m_ui->m_btnTopicSet2Down, SIGNAL(clicked()), this, SLOT(moveTopicSet2Down()));
  
  
  //setting topic enditor enbled for adding topics  
  setTopicEditorEnabled(true);
  updateTopicSet1Count();
  updateTopicSet2Count();
  checkName();
  checkAuthor();
  qRegisterMetaType<MatchTopic>("Match Topic");
}

MatchEditor::~MatchEditor() {
  qDebug("Destroying MatchEditor instance.");

  delete m_ui;
}


// function which return Topics for set 1
QList<MatchTopic> MatchEditor::activeTopicsSet1() const {
  QList<Topic> topicsset1;

  for (int i = 0; i < m_ui->m_listTopicsSet1->count(); i++) {
    topicsset1.append(m_ui->m_listTopicsSet1->item(i)->data(Qt::UserRole).value<MatchTopic>()); 
  }

  return topicsset1;
}

// function which return Topics for set 2
QList<MatchTopic> MatchEditor::activeTopicsSet2() const {
  QList<Topic> topicsset2;

  for (int i = 0; i < m_ui->m_listTopicsSet2->count(); i++) {
    topicsset2.append(m_ui->m_listTopicsSet2->item(i)->data(Qt::UserRole).value<MatchTopic>()); ///
  }

  return topicsset2;
}



QString MatchEditor::projectName() {
  return m_ui->m_txtName->lineEdit()->text();
}

QString MatchEditor::authorName() {
  return m_ui->m_txtAuthor->lineEdit()->text();
}


// Adding new topic to set1 
void MatchEditor::addTopicSet1(const QString &topicset1,int correct_answer) {
  MatchTopic new_topicset1;

  new_topicset1.setTopic(topicset1);
  new_topicset1.setCorrectAnswer(correct_answer);

  int marked_topicset1 = m_ui->m_listTopicsSet1->currentRow();
  QListWidgetItem *new_item = new QListWidgetItem();
  new_item->setText(new_topicset1.topic());

  if (m_ui->m_listTopicsSet1->count() == 0) {
    // We are adding first topic to set 1.
         
    m_ui->m_btnTopicSet1Remove->setEnabled(true);

    m_ui->m_listTopicsSet1->insertItem(0, new_item);
    m_ui->m_listTopicsSet1->setCurrentRow(0);
  }
  else {
    m_ui->m_listTopicsSet1->insertItem(marked_topicset1 + 1, new_item);
    m_ui->m_listTopicsSet1->setCurrentRow(marked_topicset1 + 1);
  }

  
  //updating topic count  in set1 after adding topic  
  updateTopicSet1Count(); 
}



// Adding new topic to set2  
void MatchEditor::addTopicSet2(const QString &topicset2) {
  Topic new_topicset2;

  new_topicset2.setTopic(topicset2);

  int marked_topicset2 = m_ui->m_listTopicsSet2->currentRow();
  QListWidgetItem *new_item = new QListWidgetItem();
  new_item->setText(new_topicset2.topic());

  if (m_ui->m_listTopicsSet2->count() == 0) {
    // We are adding first topic to set 1.
	
    m_ui->m_btnTopicSet2Remove->setEnabled(true);

    m_ui->m_listTopicsSet2->insertItem(0, new_item);
    m_ui->m_listTopicsSet2->setCurrentRow(0);
  }
  else {
    m_ui->m_listTopicsSet2->insertItem(marked_topicset2 + 1, new_item);
    m_ui->m_listTopicsSet2->setCurrentRow(marked_topicset2 + 1);
  }
 // updating Topic count after adding a topic in  set 2 
  updateTopicSet2Count(); 
}


void MatchEditor::loadTOpicSet1(int index) {
  m_ui->m_txtTopicSet1->blockSignals(true);
  m_ui->m_txtTopicSet1Answer->blockSignals(true);

  if (index >= 0) {
    Topic topicset1 = m_ui->m_listQuestions->item(index)->text();
    m_ui->m_txtTopicSet1->setText(topicset1.topic());
	m_ui->m_txtTopicSet1Answer->setText(topicset1.correctAnswer());
   
    m_activeTopicSet1 = topicset1;
  }
  else {
    m_ui->m_txtTopicSet1->setText(QString());
    m_ui->m_txtTopicSet1Answer->setText(QString());
  }

  m_ui->m_txtTopicSet1->blockSignals(false);
  m_ui->m_txtTopicSet1Answer->blockSignals(false);
 
  QTimer::singleShot(0, this, SLOT(configureUpDownSet1()));  
}


void MatchEditor::loadTOpicSeT2(int index) {
  m_ui->m_txtTopicSet2->blockSignals(true);

  if (index >= 0) {
    Topic topicset2 = m_ui->m_listQuestions->item(index)->text();
    m_ui->m_txtTopicSet2->setText(topicset2.topic());
   
    m_activeTopicSet2 = topicset2;
  }
  else {
    m_ui->m_txtTopicSet2->setText(QString());

  }

  m_ui->m_txtTopicSet2->blockSignals(false);
 
  QTimer::singleShot(0, this, SLOT(configureUpDownSet2()));   
}


void MatchEditor::removeTopicSet1() {
  int current_row = m_ui->m_listTopicsSet1->currentRow();

  if (current_row >= 0) {
    if (m_ui->m_listTopicsSet1->count() == 1) {
      // We are removing last visible topic from set 1.

      m_ui->m_btnTopicSet1Remove->setEnabled(false);
    }

    delete m_ui->m_listTopicsSet1->takeItem(current_row);
  }

  //updating topic in set 1 after removing topic 
  updateTopicSet1Count();

  //emmiting changes after removing set 1 topic   
  launch();       
  emit changed();  
}


void MatchEditor::removeTopicSet2() {
  int current_row = m_ui->m_listTopicsSet2->currentRow();

  if (current_row >= 0) {
    if (m_ui->m_listTopicsSet2->count() == 1) {
      // We are removing last visible topic from set 1.

      m_ui->m_btnTopicSet1Remove->setEnabled(false);
    }

    delete m_ui->m_listTopicsSet2->takeItem(current_row);
  }

  updateTopicSet2Count();
  //emitting changes after removing topic in set 2
  launch();       
  emit changed(); 
}



void MatchEditor::saveTopicSet1() {

  m_activeTopicSet1.setTopicSet1(m_ui->m_txtTopicSet1->toPlainText());
  m_activeTopicSet1.setCorrectAnswer(m_txtTopicSet1Answer->text());
  m_ui->m_listTopicsSet1->currentItem()->setText(m_activeTopicSet1.topic());

  emit changed();  
}



void MatchEditor::saveTopicSet2() {

  m_activeTopicSet2.setTopicSet2(m_ui->m_txtTopicSet2->toPlainText());
  m_ui->m_listTopicsSet2->currentItem()->setText(m_activeTopicSet2.topic());

  emit changed();  
}


void MatchEditor::moveTopicSet1Up() {
  int index = m_ui->m_listTopicsSet1->currentRow();

  m_ui->m_listTopicsSet1->insertItem(index - 1, m_ui->m_listTopicsSet1->takeItem(index));
  m_ui->m_listTopicsSet1->setCurrentRow(index - 1);

  emit changed(); 
}

void MatchEditor::moveTopicSet2Up() {
  int index = m_ui->m_listTopicsSet2->currentRow();

  m_ui->m_listTopicsSet2->insertItem(index - 1, m_ui->m_listTopicsSet2->takeItem(index));
  m_ui->m_listTopicsSet2->setCurrentRow(index - 1);

  emit changed(); 
}


void MatchEditor::moveTopicSet1Down() {
  int index = m_ui->m_listToicsSet1->currentRow();

  m_ui->m_listTopicsSet1->insertItem(index + 1, m_ui->m_listTopicsSet1->takeItem(index));
  m_ui->m_listTopicsSet1->setCurrentRow(index + 1);

  emit changed();
}


void MatchEditor::moveTopicSet2Down() {
  int index = m_ui->m_listToicsSet2->currentRow();

  m_ui->m_listTopicsSet2->insertItem(index + 1, m_ui->m_listTopicsSet2->takeItem(index));
  m_ui->m_listTopicsSet2->setCurrentRow(index + 1);

  emit changed(); 
}


void MatchEditor::configureUpDownSet1() {
  if (m_ui->m_listTopicsSet1->count() > 1) {
    int index = m_ui->m_listTopicsSet1->currentRow();

    if (index == 0) {
      m_ui->m_btnTopicSet1Up->setEnabled(false);
      m_ui->m_btnTopicSet1Down->setEnabled(true);
    }
    else if (index == m_ui->m_listTopicsSet1->count() - 1) {
      m_ui->m_btnTopicSet1Up->setEnabled(true);
      m_ui->m_btnTopicSet1Down->setEnabled(false);
    }
    else {
      m_ui->m_btnTopicSet1Up->setEnabled(true);
      m_ui->m_btnTopicSet1Down->setEnabled(true);
    }
  }
  else {
    m_ui->m_btnTopicSet1Up->setEnabled(false);
    m_ui->m_btnTopicSet1Down->setEnabled(false);
  }
}


void MatchEditor::configureUpDownSet2() {
  if (m_ui->m_listTopicsSet2->count() > 1) {
    int index = m_ui->m_listTopicsSet2->currentRow();

    if (index == 0) {
      m_ui->m_btnTopicSet2Up->setEnabled(false);
      m_ui->m_btnTopicSet2Down->setEnabled(true);
    }
    else if (index == m_ui->m_listTopicsSet1->count() - 1) {
      m_ui->m_btnTopicSet2Up->setEnabled(true);
      m_ui->m_btnTopicSet2Down->setEnabled(false);
    }
    else {
      m_ui->m_btnTopicSet2Up->setEnabled(true);
      m_ui->m_btnTopicSet2Down->setEnabled(true);
    }
  }
  else {
    m_ui->m_btnTopicSet2Up->setEnabled(false);
    m_ui->m_btnTopicSet2Down->setEnabled(false);
  }
}


void MatchEditor::setTopicEditorEnabled(bool enabled) {
  m_ui->m_groupTopicEditor->setEnabled(enabled);
}

void MatchEditor::checkName() {
  if (m_ui->m_txtName->lineEdit()->text().simplified().isEmpty()) {
    m_ui->m_txtName->setStatus(WidgetWithStatus::Error, tr("Enter the name of the test."));
  }
  else {
    m_ui->m_txtName->setStatus(WidgetWithStatus::Ok, tr("Name is okay."));
  }
}

void MatchEditor::checkAuthor() {
  if (m_ui->m_txtAuthor->lineEdit()->text().simplified().isEmpty()) {
    m_ui->m_txtAuthor->setStatus(WidgetWithStatus::Error, tr("Enter the name of the author of the test."));
  }
  else {
    m_ui->m_txtAuthor->setStatus(WidgetWithStatus::Ok, tr("Enter the name of the author of the test."));
  }
}

void MatchEditor::updateNameStatus() {
  checkName();
  launch();
  emit changed();
}

void MatchEditor::updateAuthorStatus() {
  checkAuthor();
  launch();
  emit changed();
}

bool MatchEditor::canGenerateApplications() {
  return
      !m_ui->m_txtName->lineEdit()->text().simplified().isEmpty() &&
      !m_ui->m_txtAuthor->lineEdit()->text().simplified().isEmpty() &&
      !activeTopicsSet1().isEmpty() && 
	  !activeTopicsSet2().isEmpty() && 
	  (m_ui->m_listTopicsSet1->count() == m_ui->m_listTopicsSet1->count());   // checking that equal no of topics present in both sets
	  
}

bool MatchEditor::loadBundleData(const QString &bundle_data) {
  QDomDocument bundle_document;
  bundle_document.setContent(bundle_data);

  
  //Load topics of set1
  QDomNodeList items = bundle_document.documentElement().elementsByTagName("item1");
  for (int i = 0; i < items.size(); i++) {
    QDomNode item = items.at(i);

    if (item.isElement()) {
      QString topicset1 = item.namedItem("topicset1").toElement().text();
      int topicset1correct_answer = item.namedItem("answerset").toElement().text().toInt();

      if (topicset1.isEmpty()) {
        // TODO: error
        continue;
      }
      else {
        addTopicSet1(topicset1, topicset1correct_answer);
      }
    }
    else {
      continue;
    }
  }
  
  
  
  //Load topics of set 2
  QDomNodeList items = bundle_document.documentElement().elementsByTagName("item2");
  for (int i = 0; i < items.size(); i++) {
    QDomNode item = items.at(i);

    if (item.isElement()) {
      QString topicset2 = item.namedItem("topicset2").toElement().text();
	  
      if (topicset2.isEmpty()) {
        // TODO: error
        continue;
      }
      else {
        addTopicSet2(topicset2);
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

QString MatchEditor::generateBundleData() {
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

  foreach (const MatchTopic &topic, activeTopicsSet1().) {
    QDomElement item_element = source_document.createElement("item1");

    // Fill in details about question.
    QDomElement topicset1_element = source_document.createElement("topicset1");
    QDomElement topicset1_answer = source_document.createElement("answerset1"); 	
    topicset1_element.appendChild(source_document.createTextNode(topic.topic()));
	topicset1_answer.appendChild(source_document.createTextNode(QString::number(topic.correctAnswer())));
    item_element.appendChild(topicset1_element);
	item_element.appendChild(topicset1_answer);
    data_element.appendChild(item_element);
  }
  
  foreach (const MatchTopic &topic, activeTopicsSet2().) {
    QDomElement item_element = source_document.createElement("item2");

    // Fill in details about question.
    QDomElement topicset2_element = source_document.createElement("topic2"); 
    topicset2_element.appendChild(source_document.createTextNode(topic.topic()));
    item_element.appendChild(topicset1_element);
    data_element.appendChild(item_element);
  }

  return source_document.toString(XML_BUNDLE_INDENTATION);
}
