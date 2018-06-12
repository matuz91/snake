//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef SNAKETESTAPP_H
#define SNAKETESTAPP_H

#include "MooseApp.h"

class snakeTestApp;

template <>
InputParameters validParams<snakeTestApp>();

class snakeTestApp : public MooseApp
{
public:
  snakeTestApp(InputParameters parameters);
  virtual ~snakeTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* SNAKETESTAPP_H */
