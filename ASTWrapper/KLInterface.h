// Copyright (c) 2010-2017 Fabric Software Inc. All rights reserved.

#ifndef __ASTWrapper_KLInterface__
#define __ASTWrapper_KLInterface__

#include "KLType.h"

#include <string>

namespace FabricServices
{

  namespace ASTWrapper
  {

    class KLInterface : public KLType
    {
      friend class KLNameSpace;

    public:

      virtual ~KLInterface();

      virtual KLDeclType getDeclType() const;
      virtual bool isOfDeclType(KLDeclType type) const;

      virtual bool isForwardDecl() const { return m_isForwardDecl; }

      virtual const char * getKLType() const;
      virtual std::vector<const KLType*> getParents() const;

    protected:

      KLInterface(const KLFile* klFile, const KLNameSpace * nameSpace, JSONData data);

    private:
      bool m_isForwardDecl;

    };

  };

};


#endif // __ASTWrapper_KLInterface__
