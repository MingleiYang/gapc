/* {{{

    This file is part of gapc (GAPC - Grammars, Algebras, Products - Compiler;
      a system to compile algebraic dynamic programming programs)

    Copyright (C) 2008-2011  Georg Sauthoff
         email: gsauthof@techfak.uni-bielefeld.de or gsauthof@sdf.lonestar.org

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

}}} */

#ifndef SRC_CHAR_VISITOR_HH_
#define SRC_CHAR_VISITOR_HH_

#include <list>

#include "visitor.hh"

#include "type_fwd.hh"
#include "bool.hh"

class Char_Visitor : public Visitor {
 private:
  std::list<Type::Base*> list_;
  Bool active;

 public:
  void visit_begin(Alt::Simple &a);
  void visit_end(Alt::Simple &a);
  void visit(Fn_Arg::Const &f);

  const std::list<Type::Base*> &list() const { return list_; }
};

#endif  // SRC_CHAR_VISITOR_HH_
