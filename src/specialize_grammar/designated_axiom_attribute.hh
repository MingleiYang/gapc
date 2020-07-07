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


#ifndef SRC_SPECIALIZE_GRAMMAR_DESIGNATED_AXIOM_ATTRIBUTE_HH_
#define SRC_SPECIALIZE_GRAMMAR_DESIGNATED_AXIOM_ATTRIBUTE_HH_

#include <string>
#include "../util/attribute.hh"

namespace SpecializeGrammar {
class DesignatedAxiomAttribute : public Util::Attribute {
 private:
    // The original name of the axiom the designated
    // axiom-grammar-rule replaces.
    std::string* originalAxiomName;

 public:
    DesignatedAxiomAttribute(std::string* originalAxiomName);
    DesignatedAxiomAttribute(DesignatedAxiomAttribute& a);
    virtual ~DesignatedAxiomAttribute();

    // Returns the original name of the axiom.
    std::string* getOriginalAxiomName();

    virtual Util::Attribute* clone();
};


}  // namespace SpecializeGrammar


#endif  // SRC_SPECIALIZE_GRAMMAR_DESIGNATED_AXIOM_ATTRIBUTE_HH_
