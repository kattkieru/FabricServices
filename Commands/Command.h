// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#ifndef __Commands_Command__
#define __Commands_Command__

#include <vector>

namespace FabricServices
{

  namespace Commands
  {
    class Command
    {
      friend class CommandStack;
      friend class CompoundCommand;

    public:

      Command();
      virtual ~Command();

      virtual const char * getName() const = 0;
      virtual const char * getShortDesc() const = 0;
      virtual const char * getFullDesc() const = 0;

    protected:
      
      virtual bool invoke() = 0;
      virtual bool undo() = 0;
      virtual bool redo();
      virtual void destroy(); 
    };

    typedef std::vector<Command*> CommandVector;

  };

};

#endif // __Commands_Command__
