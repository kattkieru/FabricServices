// Copyright 2010-2014 Fabric Engine Inc. All rights reserved.

#ifndef __CodeCompletion_KLSyntaxHighlighter__
#define __CodeCompletion_KLSyntaxHighlighter__

#include "SyntaxHighlighter.h"
#include <ASTWrapper/KLASTManager.h>
#include <map>

namespace FabricServices
{

  namespace CodeCompletion
  {

    class KLSyntaxHighlighter : public SyntaxHighlighter, public ASTWrapper::KLASTClient
    {
    public:

      KLSyntaxHighlighter(ASTWrapper::KLASTManager * manager = NULL);
      virtual ~KLSyntaxHighlighter();

      virtual void onFileParsed(const ASTWrapper::KLFile * file);

    private:

      void initRules();

      bool m_basicTypesInitialized;
      std::map<std::string, HighlightRule*> m_constantRules;
      std::map<std::string, HighlightRule*> m_typeRules;
    };

  };

};


#endif // __CodeCompletion_KLSyntaxHighlighter__
