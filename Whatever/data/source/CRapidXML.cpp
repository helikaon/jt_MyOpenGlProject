//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2014 Media Design School
//
// File Name	: rapidxml.cpp
// Description	: Implements the CRapidXML class.
// Author		: Rian Drake.
// Mail			: rian.drake@mediadesign.school.nz
//

// Library Includes

// Local Includes

// This Includes
#include "CRapidXML.h"

// Static Variables

// Static Function Prototypes

// Implementation
CRapidXML::CRapidXML()
	: m_pXmlFile(0)
{

}

CRapidXML::~CRapidXML()
{
	delete m_pXmlFile;
	m_pXmlFile = 0;
}

/**
* Loads and parses an XML file.
*
* @author Rian Drake.
*/
void CRapidXML::LoadFile(const std::string& _sXML)
{
	m_pXmlFile = new rapidxml::file<>(_sXML.c_str());
	m_fXmlDocument.parse<0>(m_pXmlFile->data());

	m_nodeRoot = m_fXmlDocument.first_node();
}

/**
* Returns the root node.
*
* @author Rian Drake.
*/
rapidxml::xml_node<>* CRapidXML::GetRootNode()
{
	return m_nodeRoot;
}
