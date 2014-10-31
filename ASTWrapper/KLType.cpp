// Copyright 2010-2014 Fabric Engine Inc. All rights reserved.

#include "KLType.h"

#include <map>

using namespace FabricServices::ASTWrapper;

std::map<std::string, KLType*> s_allTypes;

KLType::KLType(JSONData data)
: KLCommented(data)
{
  const char * name = getStringDictValue("name");
  if(name)
    m_name = name;

  // todo: thread safety
  if(s_allTypes.find(m_name) == s_allTypes.end())
    s_allTypes.insert(std::pair<std::string, KLType*>(m_name, this));
}

KLType::~KLType()
{
  for(unsigned int i=0;i<m_methods.size();i++)
  {
    if(m_methods[i])
      delete(m_methods[i]);
  }

  // todo: thread safety
  std::map<std::string, KLType*>::iterator it = s_allTypes.find(m_name);
  if(it != s_allTypes.end())
    s_allTypes.erase(it);
}

void KLType::setExtension(const std::string & extension)
{
  KLCommented::setExtension(extension);
  for(unsigned int i=0;i<m_methods.size();i++)
    m_methods[i]->setExtension(extension);
}

void KLType::setKLFile(const std::string & klFile)
{
  KLCommented::setKLFile(klFile);
  for(unsigned int i=0;i<m_methods.size();i++)
    m_methods[i]->setKLFile(klFile);
}

const std::string & KLType::getName() const
{
  return m_name;
}

unsigned int KLType::getMethodCount() const
{
  return m_methods.size();
}

const KLMethod * KLType::getMethod(unsigned int index) const
{
  return m_methods[index];
}

const KLMethod * KLType::getMethod(const char * labelOrName) const
{
  if(!labelOrName)
    return NULL;

  std::map<std::string, unsigned int>::const_iterator it = m_methodLabelToId.find(labelOrName);
  if(it != m_methodLabelToId.end())
    return m_methods[it->second];

  for(unsigned int i=0;i<m_methods.size();i++)
  {
    if(m_methods[i]->getName() == labelOrName)
      return m_methods[i];
  }
  return NULL;
}

std::vector<const KLMethod*> KLType::getMethods(bool includeInherited, bool includeInternal, const char * category) const
{
  std::vector<const KLMethod*> methods;

  // todo

  return methods;
}

const KLType * KLType::getKLTypeByName(const char * name)
{
  std::map<std::string, KLType*>::iterator it = s_allTypes.find(name);
  if(it != s_allTypes.end())
    return it->second;
  return NULL;
}

void KLType::pushMethod(KLMethod * method)
{
  m_methodLabelToId.insert(std::pair<std::string, unsigned int>(method->getLabel(), (unsigned int)m_methods.size()));
  m_methods.push_back(method);
}