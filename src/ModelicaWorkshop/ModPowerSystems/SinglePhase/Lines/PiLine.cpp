/*
 * PiLine.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: root
 */

#include "PiLine.h"

namespace ModPowerSystems {

namespace SinglePhase {

namespace Lines {

PiLine::PiLine() {
  // TODO Auto-generated constructor stub

}

PiLine::PiLine(const PiLine &rhs):ModBaseClass(rhs) {

  this->_length = rhs._length;
  this->_r = rhs._r;
  this->_x = rhs._x;
  this->_b = rhs._b;
  this->_g = rhs._g;
  this->_Sr = rhs._Sr;
  this->_Imax = rhs._Imax;
  this->_Imax_displayUnit = rhs._Imax_displayUnit;
  this->_Sr_displayUnit = rhs._Sr_displayUnit;
  this->_g_displayUnit = rhs._g_displayUnit;
  this->_b_displayUnit = rhs._b_displayUnit;
  this->_r_displayUnit = rhs._r_displayUnit;
  this->_x_displayUnit = rhs._x_displayUnit;
}

PiLine & PiLine::operator=(const PiLine &rhs) {

  if(this == &rhs) return *this;
  ModBaseClass::operator=(rhs);
  this->_length = rhs._length;
  this->_r = rhs._r;
  this->_x = rhs._x;
  this->_b = rhs._b;
  this->_g = rhs._g;
  this->_Sr = rhs._Sr;
  this->_Imax = rhs._Imax;
  this->_Imax_displayUnit = rhs._Imax_displayUnit;
  this->_Sr_displayUnit = rhs._Sr_displayUnit;
  this->_g_displayUnit = rhs._g_displayUnit;
  this->_b_displayUnit = rhs._b_displayUnit;
  this->_r_displayUnit = rhs._r_displayUnit;
  this->_x_displayUnit = rhs._x_displayUnit;

  return *this;
}


PiLine::~PiLine() {
  // TODO Auto-generated destructor stub
}

bool PiLine::set_template_values(ctemplate::TemplateDictionary *dictionary) {

  dictionary->SetValue(NAME, this->name());
  dictionary->SetFormattedValue(LENGTH, "%.2f", this->length());
  dictionary->SetFormattedValue(IMAX, "%.2f", this->Imax());
  dictionary->SetFormattedValue(R, "%.3f", this->r());
  dictionary->SetFormattedValue(X, "%.3f", this->x());
  dictionary->SetFormattedValue(B, "%.10f", this->b());
  dictionary->SetFormattedValue(G, "%.f", this->g());
  dictionary->SetFormattedValue(SR, "%.f", this->Sr());
  dictionary->SetValue(IMAX_DISPLAYUNIT, (ModelicaUnit[this->Imax_displayUnit()]));
  dictionary->SetValue(SR_DISPLAYUNIT, (ModelicaUnit[this->Sr_displayUnit()]));

  this->set_template_annotation_values(dictionary);

  return true;
}

} /* namespace Lines */

} /* namespace SinglePhase */

} /* namespace ModPowerSystems */
