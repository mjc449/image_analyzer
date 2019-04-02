/*
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
#ifndef IMAGE_ANALYZER_ENGINE_H_
#define IMAGE_ANALYZER_ENGINE_H_

//Simple macro for function export when compiling driver
#ifdef MAKE_DLL_
#define IMAGE_ANALYZER_API_      __declspec(dllexport)
#else
#define IMAGE_ANALYZER_API_      __declspec(dllimport)
#endif //MAKE_DLL_

/**
*Image analysis and data fitting API entry point.
*/
namespace ImageAnalyzerAPI
{
   class Analyzer
   {
   public:
      virtual ~Analyzer();

      /**
      * Return codes for member functions
      */
      enum AnalyzerError
      {
         ANALYZER_OK, /**<Successful function call*/
         ANALYZER_FAILED_DESTRUCT, /**<Resource deallocation failed*/
         ANALYZER_FAILED_INITIALIZE, /**<Allocation failed on initialization*/
         ANALYZER_BAD_PARAMETER_TYPE, /**<Parameter invalid for fitter type*/
         ANALYZER_BAD_PARAMETER_VALUE /**<Incorrect parameter type of value out of range*/
      };

      /**
      * Parameter list.  Not all parameters are pertinent to all fitter types.
      * Parameters are stored internally, current values can be retireved
      * through parameter_get() or set through parameter_set()*/
      enum AnalyzerParameter
      {
         IMAGE_DIMENSIONS /**<Override the image dimensions to create an ROI within the image.  In the case of an image stack the ROI is copied to all images vertically.*/
      };

      /** @brief Closedown the fitter
      *
      * Deinitialies the fitter and frees resources.  Calls to Destroy() will
      * invalidate any member data or functions.  Fitter must not be accessed
      * after calls to Destroy.  Returns 
      */
      virtual AnalyzerError Destroy() = 0;

      /** @brief Begins the fitter instance and allocates buffers
      *
      * Creates a fitter instance of the appropriate type.  Internal buffers are
      * allocated and intial default values for fit parameters are set.  Values
      * can be changed or reset through the appropriate function calls following
      * initialization.*/
      virtual AnalyzerError Initialize() = 0;

      //@{
      /** Set or update analysis parameters
      * @param paramType Fitter specific parameter value to be updated
      * @param paramVal New parameter value
      * @retval Returns Returns ANALYZER_OK on success, ANALYZER_BAD_PARAMETER_*
      * on failure
      */
      virtual AnalyzerError SetParameter(AnalyzerParameter, short) = 0;
      virtual AnalyzerError SetParameter(AnalyzerParameter, int) = 0;
      virtual AnalyzerError SetParameter(AnalyzerParameter, float) = 0;
      virtual AnalyzerError SetParameter(AnalyzerParameter, double) = 0;
      virtual AnalyzerError SetParameter(AnalyzerParameter, short*) = 0;
      virtual AnalyzerError SetParameter(AnalyzerParameter, int*) = 0;
      virtual AnalyzerError SetParameter(AnalyzerParameter, float*) = 0;
      virtual AnalyzerError SetParameter(AnalyzerParameter, double*) = 0;
      //@}
   };
}

#endif //IMAGE_ANALYZER_ENGINE_H_