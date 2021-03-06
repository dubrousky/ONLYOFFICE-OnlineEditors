﻿/*
 * (c) Copyright Ascensio System SIA 2010-2014
 *
 * This program is a free software product. You can redistribute it and/or 
 * modify it under the terms of the GNU Affero General Public License (AGPL) 
 * version 3 as published by the Free Software Foundation. In accordance with 
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect 
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For 
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under 
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
 #pragma once
#ifndef XML_PRIVATE_ELEMENT_INCLUDE_H_
#define XML_PRIVATE_XELEMENT_INCLUDE_H_

#include <list>
#include <string>

#include "NodeContainer.h"
#include "property.h"
#include "XAttributeContainer.h"
#include "XNamespaceContainer.h"
#include "./../XName.h"
#include "XString.h"
#include "XSpace.h"
#include "XSingleSource.h"
#include "XWideSource.h"

namespace XML
{
	class XAttribute;
	class XNamespace;
	class XNode;
	class XText;
	class XContainer;
	
	namespace Private
	{
		class XList;

		class Element : public NodeContainer
		{
		public:
			Element();
			Element(const XML::XName& xname);
			Element(const XML::XName& xname, const XList& list);
			Element(NSCommon::smart_ptr<XSingleSource> source, const XNamespaceContainer& ns, const XSpace& space);
			Element(NSCommon::smart_ptr<XWideSource> source, const XNamespaceContainer& ns, const XSpace& space);

			virtual ~Element();

		public:
			virtual const bool isElement() const;
			virtual const bool isText() const;
			virtual const bool isComment() const;

		public:
			void fromSource(NSCommon::smart_ptr<XSingleSource> source, const XNamespaceContainer& defineNamespaces, const XSpace& space);
			void fromSource(NSCommon::smart_ptr<XWideSource> source, const XNamespaceContainer& defineNamespaces, const XSpace& space);
			virtual const std::string ToString() const;
			virtual const std::wstring ToWString() const;
			virtual void SaveToStringList(std::list<std::string>& strList)const;
			virtual void SaveToWStringList(std::list<std::wstring>& strList)const;

		public:
			virtual const bool exist() const;
			virtual const XString text() const;
			const XNamespaceContainer usedNamespace() const;

		public:
			void Add(const XAttribute& attribute);
			void Add(const XNamespace& ns);
			void Add(const XNode& node);
			void Add(const XElement& element);
			void Add(const XText& text);
			void Add(const XML::XContainer& container);
			void Add(const XML::Private::XList& list);

		public:
			XAttribute& attribute(const XName& xname);
			const XAttribute& attribute(const XName& xname) const;

			XElement element(const XName& xname);
			const XElement element(const XName& xname) const;

			XElement element(const XName& xname, const std::string& value);
			const XElement element(const XName& xname, const std::string& value) const;

		public:
			property<XName>						XName;
			XAttributeContainer				Attributes;
			XNamespaceContainer				Namespaces;
			property<XSpace>					Space;
		};
	} 
} 

#endif // XML_XELEMENT_INCLUDE_H_