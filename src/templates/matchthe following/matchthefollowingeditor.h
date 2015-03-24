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

#ifndef MATCHTHEFOLLOWINGEDITOR_H
#define MATCHTHEFOLLOWINGEDITOR_H

#include "core/templateeditor.h"

#include "ui_matchthefollowingeditor.h"
#include "templates/matchthefollowing/matchthefollowingtopic.h"

#include <QIcon>


namespace Ui {
  class MatchEditor;
}

class MatchSimulator;
class QShowEvent;


class MatchEditor : public TemplateEditor {
    Q_OBJECT

    friend class MatchSimulator;
    friend class MatchCore;

  public:
    // Constructors and destructors.
    explicit MatchEditor(TemplateCore *core, QWidget *parent = 0);
    virtual ~MatchEditor();

    QString generateBundleData();
    bool canGenerateApplications();
    bool loadBundleData(const QString &bundle_data);

    
    QList<MatchTopic> activeTopicsSet1() const;
	QList<MatchTopic> activeTopicsSet2() const;

    QString projectName();
    QString authorName();

  private slots:
    void updateTopicSet1Count();
	void updateTopicSet2Count();
    void addTopicSet1(const QString &topic, int correct_answer);
	void addTopicSet2(const QString &topic);
    void loadTopicSet1(int index);
	void loadTopicSet2(int index);
    void removeTopicSet1();
	void removeTopicSet2();
    void saveTopicSet1();
	void saveTopicSet2();
    void moveTopicSet1Up();
	void moveTopicSet2Up();
    void moveTopicSet1Down();
	void moveTopicSet2Down();
	

    void configureUpDownSet1();
    void configureUpDownSet2();
    void setTopicEditorEnabled(bool enabled);
    void checkName();
    void checkAuthor();

    void updateNameStatus();
    void updateAuthorStatus();

  private:
    MatchTopic m_activeTopicSet1;
	MatchTopic m_activeTopicSet2;
    Ui::QuizEditor *m_ui;
};

#endif // MATCHTHEFOLLOWINGEDITOR_H
