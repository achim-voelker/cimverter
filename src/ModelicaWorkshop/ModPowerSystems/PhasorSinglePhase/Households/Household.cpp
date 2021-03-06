/*
 * Household.cpp
 *
 */

#include "Household.h"

namespace ModPowerSystems {
namespace PhasorSinglePhase {
namespace Households {

//Default Type1
Household::Household():_Type(HouseholdType::Type1) {
  // TODO Auto-generated constructor stub

}

Household::Household(enum HouseholdType Type):_Type(Type) {

  this->annotation.placement.visible = true;
  this->annotation.placement.transformation.rotation = 0;

}

Household::Household(const Loads::PQLoad pq_load):_Type(HouseholdType::Type1) {

  if (pq_load.PQLoadType() == PQLoadType::Standard) {
    this->set_Load_Type(1);
  } else if (pq_load.PQLoadType() == PQLoadType::Profile){
    this->set_Load_Type(2);
    this->set_Load_Pnom(pq_load.Pnom());
    this->set_Load_Qnom(pq_load.Qnom());
  } else if(pq_load.PQLoadType() == PQLoadType::NormProfile){
    this->set_Load_Type(3);
  }

  this->set_name(pq_load.name());
  this->set_Household_Vnom(pq_load.Vnom());
  this->set_sequenceNumber(pq_load.sequenceNumber());
  this->set_connected(pq_load.is_connected());
  this->annotation.placement.visible = true;
  this->annotation.placement.transformation.origin.x = pq_load.annotation.placement.transformation.origin.x;
  this->annotation.placement.transformation.origin.y = pq_load.annotation.placement.transformation.origin.y;
  this->annotation.placement.transformation.rotation = 0;
}

Household::Household(const Loads::PQLoad pq_load,const Generations::SolarGenerator solar_generator):_Type(HouseholdType::Type2) {

  if (pq_load.PQLoadType() == PQLoadType::Standard) {
    this->set_Load_Type(1);
  } else if (pq_load.PQLoadType() == PQLoadType::Profile){
    this->set_Load_Type(2);
    this->set_Load_Pnom(pq_load.Pnom());
    this->set_Load_Qnom(pq_load.Qnom());
  } else if(pq_load.PQLoadType() == PQLoadType::NormProfile){
    this->set_Load_Type(3);
  }

  this->set_name(pq_load.name());
  this->set_Household_Vnom(pq_load.Vnom());
  this->set_sequenceNumber(pq_load.sequenceNumber());
  this->set_connected(pq_load.is_connected());
  this->annotation.placement.visible = true;
  this->annotation.placement.transformation.origin.x = pq_load.annotation.placement.transformation.origin.x;
  this->annotation.placement.transformation.origin.y = pq_load.annotation.placement.transformation.origin.y;
  this->annotation.placement.transformation.rotation = 0;
}

Household::Household(enum HouseholdType Type, std::string load_profileFileName, std::string load_profileName): _Type(Type),
    _Load_ProfileFileName(load_profileFileName), _Load_ProfileName(load_profileName) {

}

Household::Household(enum HouseholdType Type, std::string load_profileFileName, std::string load_profileName,
              std::string pv_profileFileName, std::string pv_profileName):_Type(Type), _Load_ProfileFileName(load_profileFileName), _Load_ProfileName(load_profileName),
                  _PV_ProfileFileName(pv_profileFileName), _PV_ProfileName(pv_profileName){

}


Household::Household(const Household &rhs) : ModBaseClass(rhs) {

  this->_Type = rhs._Type;
  this->_Load_Type = rhs._Load_Type;
  this->_Household_Vnom = rhs._Household_Vnom;
  this->_Load_Pnom = rhs._Load_Pnom;
  this->_Load_Qnom = rhs._Load_Qnom;

  this->_Household_Vnom_displayUnit = rhs._Household_Vnom_displayUnit;
  this->_Load_Pnom_displayUnit = rhs._Load_Pnom_displayUnit;
  this->_Load_Qnom_displayUnit = rhs._Load_Qnom_displayUnit;

  if((this->_Type == HouseholdType::Type1) || (this->_Type == HouseholdType::Type2)) {

    this->_Load_ProfileFileName = rhs._Load_ProfileFileName;
    this->_Load_ProfileName = rhs._Load_ProfileFileName;
  }

  if(this->_Type == HouseholdType::Type2) {

    this->_PV_Pnom = rhs._PV_Pnom;
    this->_PV_ProfileFileName = rhs._PV_ProfileFileName;
    this->_PV_ProfileName = rhs._PV_ProfileName;
    this->_PV_Controller = rhs._PV_Controller;
    this->_PV_SystemOn = rhs._PV_SystemOn;
    this->_PV_CurtailmentLimit = rhs._PV_CurtailmentLimit;
    this->_PV_Pnom_displayUnit = rhs._PV_Pnom_displayUnit;
  }
}

Household& Household::operator=(const Household &rhs) {

  if(this == &rhs) return *this;

  this->_Type = rhs._Type;
  this->_Load_Type = rhs._Load_Type;
  this->_Household_Vnom = rhs._Household_Vnom;
  this->_Load_Pnom = rhs._Load_Pnom;
  this->_Load_Qnom = rhs._Load_Qnom;

  this->_Household_Vnom_displayUnit = rhs._Household_Vnom_displayUnit;
  this->_Load_Pnom_displayUnit = rhs._Load_Pnom_displayUnit;
  this->_Load_Qnom_displayUnit = rhs._Load_Qnom_displayUnit;

  if((this->_Type == HouseholdType::Type1) || (this->_Type == HouseholdType::Type2)) {

    this->_Load_ProfileFileName = rhs._Load_ProfileFileName;
    this->_Load_ProfileName = rhs._Load_ProfileFileName;
  }

  if(this->_Type == HouseholdType::Type2) {

    this->_PV_Pnom = rhs._PV_Pnom;
    this->_PV_ProfileFileName = rhs._PV_ProfileFileName;
    this->_PV_ProfileName = rhs._PV_ProfileName;
    this->_PV_Controller = rhs._PV_Controller;
    this->_PV_SystemOn = rhs._PV_SystemOn;
    this->_PV_CurtailmentLimit = rhs._PV_CurtailmentLimit;
    this->_PV_Pnom_displayUnit = rhs._PV_Pnom_displayUnit;
  }
  return *this;
}

Household::~Household() {
  // TODO Auto-generated destructor stub
}

bool Household::set_template_values(ctemplate::TemplateDictionary *dictionary) {

   if(this->_Type == HouseholdType::Type1) {

     switch(this->Load_Type()) {
        case 1:{
          dictionary->AddSectionDictionary("LOADTYPE1_SECTION");
          dictionary->SetValue("NAME", this->name());
          dictionary->SetFormattedValue("HOUSEHOLD_VNOM", "%.3f", this->Household_Vnom());
          dictionary->SetIntValue("LOAD_TYPE", this->Load_Type());
          dictionary->ShowSection("LOADTYPE1_SECTION");
          break;
        }
        case 2:{
          dictionary->AddSectionDictionary("LOADTYPE2_SECTION");
          dictionary->SetValue("NAME", this->name());
          dictionary->SetFormattedValue("HOUSEHOLD_VNOM", "%.3f", this->Household_Vnom());
          dictionary->SetFormattedValue("LOAD_PNOM", "%.3f", this->Load_Pnom());
          dictionary->SetFormattedValue("LOAD_QNOM", "%.3f", this->Load_Qnom());
          dictionary->SetIntValue("LOAD_TYPE", this->Load_Type());
          dictionary->SetValue("LOAD_PROFILE_NAME", this->Load_ProfileName());
          dictionary->SetValue("LOAD_PROFILE_FILENAME", this->Load_ProfileFileName());
          dictionary->ShowSection("LOADTYPE2_SECTION");
          break;
        }
        case 3:{
          dictionary->AddSectionDictionary("LOADTYPE3_SECTION");
          dictionary->ShowSection("LOADTYPE3_SECTION");
          dictionary->SetValue("NAME", this->name());
          dictionary->SetFormattedValue("HOUSEHOLD_VNOM", "%.3f", this->Household_Vnom());
          dictionary->SetIntValue("LOAD_TYPE", this->Load_Type());
          dictionary->SetValue("LOAD_PROFILE_NAME", this->Load_ProfileName());
          dictionary->SetValue("LOAD_PROFILE_FILENAME", this->Load_ProfileFileName());
          dictionary->ShowSection("LOADTYPE3_SECTION");
          break;
        }
      }

  } else if(this->_Type == HouseholdType::Type2) {

     switch(this->Load_Type()) {
       case 1:{
         dictionary->AddSectionDictionary("LOADTYPE1_SECTION");
         dictionary->SetValue("NAME", this->name());
         dictionary->SetFormattedValue("HOUSEHOLD_VNOM", "%.3f", this->Household_Vnom());
         dictionary->SetIntValue("LOAD_TYPE", this->Load_Type());

         dictionary->SetFormattedValue("PV_PNOM", "%.3f", this->PV_Pnom());
         dictionary->SetValue("PV_PROFILE_NAME", this->PV_ProfileName());
         dictionary->SetValue("PV_PROFILE_FILENAME", this->PV_ProfileFileName());
         dictionary->SetIntValue("PV_CONTROLLER", this->PV_Controller());
         dictionary->SetValue("PV_SYSTEMON", this->PV_SystemOn());
         dictionary->SetIntValue("PV_CURTAILMENT_LIMIT", this->PV_CurtailmentLimit());
         dictionary->ShowSection("LOADTYPE1_SECTION");
         break;
       }
       case 2:{
         dictionary->AddSectionDictionary("LOADTYPE2_SECTION");
         dictionary->SetValue("NAME", this->name());
         dictionary->SetFormattedValue("HOUSEHOLD_VNOM", "%.3f", this->Household_Vnom());
         dictionary->SetFormattedValue("LOAD_PNOM", "%.3f", this->Load_Pnom());
         dictionary->SetFormattedValue("LOAD_QNOM", "%.3f", this->Load_Qnom());
         dictionary->SetIntValue("LOAD_TYPE", this->Load_Type());
         dictionary->SetValue("LOAD_PROFILE_NAME", this->Load_ProfileName());
         dictionary->SetValue("LOAD_PROFILE_FILENAME", this->Load_ProfileFileName());

         dictionary->SetFormattedValue("PV_PNOM", "%.3f", this->PV_Pnom());
         dictionary->SetValue("PV_PROFILE_NAME", this->PV_ProfileName());
         dictionary->SetValue("PV_PROFILE_FILENAME", this->PV_ProfileFileName());
         dictionary->SetIntValue("PV_CONTROLLER", this->PV_Controller());
         dictionary->SetValue("PV_SYSTEMON", this->PV_SystemOn());
         dictionary->SetIntValue("PV_CURTAILMENT_LIMIT", this->PV_CurtailmentLimit());
         dictionary->ShowSection("LOADTYPE2_SECTION");
         break;
       }
       case 3:{
         dictionary->AddSectionDictionary("LOADTYPE3_SECTION");
         dictionary->SetValue("NAME", this->name());
         dictionary->SetFormattedValue("HOUSEHOLD_VNOM", "%.3f", this->Household_Vnom());
         dictionary->SetIntValue("LOAD_TYPE", this->Load_Type());
         dictionary->SetValue("LOAD_PROFILE_NAME", this->Load_ProfileName());
         dictionary->SetValue("LOAD_PROFILE_FILENAME", this->Load_ProfileFileName());

         dictionary->SetFormattedValue("PV_PNOM", "%.3f", this->PV_Pnom());
         dictionary->SetValue("PV_PROFILE_NAME", this->PV_ProfileName());
         dictionary->SetValue("PV_PROFILE_FILENAME", this->PV_ProfileFileName());
         dictionary->SetIntValue("PV_CONTROLLER", this->PV_Controller());
         dictionary->SetValue("PV_SYSTEMON", this->PV_SystemOn());
         dictionary->SetIntValue("PV_CURTAILMENT_LIMIT", this->PV_CurtailmentLimit());
         dictionary->ShowSection("LOADTYPE3_SECTION");
         break;
       }
     }
  }

  this->set_template_annotation_values(dictionary);

  return true;
}

} /* namespace Households */
} /* namespace PhasorSinglePhase */
} /* namespace ModPowerSystems */
