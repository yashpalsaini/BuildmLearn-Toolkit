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

#ifndef SAMPLEEDITOR_H
#define SAMPLEEDITOR_H

#include "core/templateeditor.h"

#include "ui_sampleeditor.h"
#include "templates/sample/samplequestion.h"

#include <QIcon>


namespace Ui {
  class SampleEditor;
}

class SampleSimulator;
class QShowEvent;

/// \brief Editor for Sample.
/// \ingroup template-sample
class SampleEditor : public TemplateEditor {
    Q_OBJECT

    friend class SampleSimulator;
    friend class SampleCore;

  public:
    // Constructors and destructors.
    explicit SampleEditor(TemplateCore *core, QWidget *parent = 0);
    virtual ~SampleEditor();

    QString generateBundleData();
    bool canGenerateApplications();
    bool loadBundleData(const QString &bundle_data);

    /// \brief Access to list of added questions.
    /// \return Returns list of added questions.
    QList<SampleQuestion> activeQuestions() const;

    QString projectName();
    QString authorName();

  private slots:
    void updateQuestionCount();
    void addQuestion(const QString &question, const QString &answer);
    void loadQuestion(int index);
    void removeQuestion();
    void saveQuestion();
    void moveQuestionUp();
    void moveQuestionDown();

    void configureUpDown();
    void setEditorsEnabled(bool enabled);

    void checkName();
    void checkAuthor();

    void updateNameStatus();
    void updateAuthorStatus();

  private:
    SampleQuestion m_activeQuestion;
    Ui::SampleEditor *m_ui;
    QIcon m_iconYes;
    QIcon m_iconNo;
};

#endif // SAMPLEEDITOR_H
