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

#ifndef DICTATIONEDITOR_H
#define DICTATIONEDITOR_H

#include "core/templateeditor.h"

#include "ui_dictationeditor.h"
#include "templates/dictation/dictationpassage.h"



namespace Ui {
  class DictationEditor;
}

class DictationSimulator;
class QShowEvent;

/// \brief Editor for DICTATION.
class DictationEditor : public TemplateEditor {
    Q_OBJECT

    friend class DictationSimulator;
    friend class DictationCore;

  public:
    // Constructors and destructors.
    explicit DictationEditor(TemplateCore *core, QWidget *parent = 0);
    virtual ~DictationEditor();

    QString generateBundleData();
    bool canGenerateApplications();
    bool loadBundleData(const QString &bundle_data);
	
    DictationPassage activePassage() const;
    QString projectName();
    QString authorName();

  private slots:
    void addPassage(const QString &passage);
    void removePassage();
    void savePassage();

    void setEditorEnabled(bool enabled);

    void checkName();
    void checkAuthor();

    void updateNameStatus();
    void updateAuthorStatus();

  private:
    DictationPassage m_activePassage;
    Ui::DictationEditor *m_ui;
};

#endif // DICTATIONEDITOR_H
