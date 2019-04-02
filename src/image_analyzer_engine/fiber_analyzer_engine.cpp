/**
Copyright (c) 2019 Marshall Colville mjc449@cornell.edu

Redistribution  and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistribution or source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions, and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "image_analyzer_engine.h"

namespace ImageAnalyzerAPI
{
#define OK_ Analyzer::ANALYZER_ERROR::ANALYZER_OK

   /**Definition for the collagen fiber confocal reflection microscopy
   image analyzer class*/
   class FiberAnalyzer : public Analyzer {
   public:
      virtual ~FiberAnalyzer()
      {

      }

      FiberAnalyzer()
      {

      }

      ANALYZER_ERROR Destroy()
      {
         return OK_;
      }

      ANALYZER_ERROR Initialize()
      {
         return OK_;
      }

      ANALYZER_ERROR SetInputPath(std::string inputPath)
      {
         return OK_;
      }

      ANALYZER_ERROR SetOutputPath(std::string outputPath)
      {
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         short val)
      {
         switch (type){
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         int val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         float val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         double val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         short *val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         int *val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         float *val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         double *val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         impoint val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         imsize val)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }

      ANALYZER_ERROR SetParameter(
         AnalyzerParameter type,
         impoint point,
         imsize size)
      {
         switch (type) {
         default:
            return ANALYZER_ERROR::ANALYZER_BAD_PARAMETER_TYPE;
         }
         return OK_;
      }
   };

   /** Factory function definition for creating a fiber analysis instance*/
#ifdef __cplusplus
   extern "C" {
#endif
      IMAGE_ANALYZER_API_ Analyzer* __cdecl CreateFiberAnalyzer()
      {
         Analyzer* p = new FiberAnalyzer;
         return p;
      }
#ifdef __cplusplus
   }
#endif
}