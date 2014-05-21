//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: rapidxml.h
// Description	: Defines the CRapidXML class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//

#pragma once

#ifndef __RAPIDXML_H__
#define __RAPIDXML_H__

// Library Includes
#include <string>

// Local Includes
#include "rapidxml\rapidxml.hpp"
#include "rapidxml\rapidxml_utils.hpp"

// Types

// Constants
using rapidxml::xml_node;

// Prototypes
class CRapidXML
{
	// Member Functions
public:
	// Constructors/Destructors
	CRapidXML();
	~CRapidXML();

	// Methods
	void LoadFile(const std::string& _sXML);
	rapidxml::xml_node<>* GetRootNode();

protected:
private:

	// Member Variables
public:
protected:
private:
	rapidxml::file<>* m_pXmlFile;
	rapidxml::xml_document<> m_fXmlDocument;
	rapidxml::xml_node<>* m_nodeRoot;
};

#endif // __RAPIDXML_H__