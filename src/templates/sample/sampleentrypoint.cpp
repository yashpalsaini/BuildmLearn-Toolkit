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

#include "templates/sample/sampleentrypoint.h"

#include "core/templatefactory.h"
#include "templates/sample/samplecore.h"
#include "templates/sample/sampleeditor.h"
#include "templates/sample/samplesimulator.h"


SampleEntryPoint::SampleEntryPoint(TemplateFactory *parent) : TemplateEntryPoint(parent) {
  m_baseFolder = "sample";
  m_description = "Choose this template to create Sample-like applications.";
  m_humanName = "Sample";
  m_name = "sample";
  m_thumbnailImage = "thumbnail.png";
  m_typeIndentifier = "SampleTemplate";
  m_mobileApplicationApkFile = "SampleTemplateApp.apk";
}

SampleEntryPoint::~SampleEntryPoint() {
}

TemplateCore *SampleEntryPoint::createNewCore() {
  return new SampleCore(this, this);
}

TemplateCore *SampleEntryPoint::loadCoreFromBundleData(const QString &raw_data) {
  SampleCore *core = new SampleCore(this, this);
  if (core->editor()->loadBundleData(raw_data)) {
    return core;
  }
  else {
    core->simulator()->deleteLater();
    core->editor()->deleteLater();
    core->deleteLater();
    return NULL;
  }
}
