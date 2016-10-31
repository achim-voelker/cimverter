/*
 * ModBaseClass.h
 *
 * Base Class for Modelica ModPowerSystems
 */

#ifndef SRC_MODELICAWORKSHOP_MODBASECLASS_H_
#define SRC_MODELICAWORKSHOP_MODBASECLASS_H_

#include <stdlib.h>
#include <iostream>
#include <ctemplate/template.h>
#include "ModelicaUnit.h"
#include "tplMarkersEnum.h"


namespace ModelicaWorkshop {

	typedef struct Point
	{
		double x;
		double y;

	} Point;

	typedef struct Extent
	{
		Point first;
		Point second;

	} Extent;

	typedef struct CoordinateSystem
	{
		Extent extent;
		bool preserveAspectRatio = false;

	} CoordinateSystem;

	typedef struct Diagram
	{
		CoordinateSystem coordinate;

	} Diagramm;

	typedef struct Icon
	{
		CoordinateSystem coordinate;

	} Icon;

	typedef struct Transformation
	{
		Extent extent = {{-5,-5},{5,5}};
		int rotation = {0};
		Point origin = {0,0};

	} Transformation;

	typedef struct Placement
	{
		bool visible = true;
		Transformation transfomation;

	} Placement;

	typedef struct Annotation {

		Placement placement;
		Diagram diagram;
		Icon icon;

	} Annotation;

	class ModBaseClass {
	public:
		ModBaseClass();
		virtual ~ModBaseClass();

		void set_name(std::string name){ this->_name = name; };
		std::string name() const { return this->_name; };
		std::map<const std::string, const std::string> ready_to_fill_templates;
		Annotation annotation;

		virtual bool set_template_values(ctemplate::TemplateDictionary *dictionary);

	private:
		std::string _name;
	};

} /* namespace ModelicaWorkshop */

#endif /* SRC_MODELICAWORKSHOP_MODBASECLASS_H_ */
