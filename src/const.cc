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


#include "const.hh"
#include "log.hh"

#include <iostream>

Const::Char::Char(const std::string &n, const Loc &l)
  : Base(CHAR, l) {
  assert(n.size() > 0);
  if (n[0] == '\\') {
    if (n.size() == 2 && n[1] < '0' && n[1] > '9') {
      switch (n[1]) {
        case 'n' : c = '\n'; break;
        case 't' : c = '\t'; break;
        default: {
                   std::ostringstream o;
                   o << "Unknown escaped char: " <<  n[1];
                   throw LogError(l, o.str());
                 }
      }
    } else {
      std::string suff(n.substr(1));
      Int i(suff, l);
      c = char(i.i);
    }
  } else {
    c = n[0];
  }

  ys.set(1, 1);
  datatype = new ::Type::Char();
}

Const::Base::~Base() {}

void Const::Base::print_type(std::ostream &s) {
  std::cout << "\n called print_type of class const \n";
  if (datatype)
    s << *datatype;
  else
    s << "NULL";
}


void Const::Base::put(std::ostream &s) {
  std::cout << "\n called put of class const \n";
}

void Const::Int::put(std::ostream &s) {
  std::cout << "\n called put of class const \n";
  s << i;
}

void Const::Size::put(std::ostream &s) {
  std::cout << "\n called put of class const \n";
  s << u;
}

void Const::Float::put(std::ostream &s) {
  std::cout << "\n called put of class const \n";
  s << std::scientific << f;
}

void Const::Char::put(std::ostream &s) {
  std::cout << "\n called put of class const \n";
  if (c < 32) {
    // s << "\'\\x" << std::hex << int(c) << std::dec << '\'';
    s << int(c);
    return;
  }
  s << '\'' << c << '\'';
}

void Const::String::put(std::ostream &o) {
  std::cout << "\n called print_type of class const \n";
  o << '"' << *s << '"';
}

void Const::Rational::put(std::ostream &o) {
  std::cout << "\n called print_type of class const \n";
  o << "Rational(\"" << *a << "/" << *b << "\")";
}

void Const::Bool::put(std::ostream &o) {
  std::cout << "\n called put of class const \n";
  o << (b ? "true" : "false");
}


void Const::Number::setNegative() {
  std::cout << "\n called setNegative of class const \n";
  Yield::Poly r(ys.high());
  r += 1;
  ys.set(ys.low(), r);
}

Const::Float::Float(double d)
  : Number(FLOAT), f(d) {
  datatype = new ::Type::Float();
}
