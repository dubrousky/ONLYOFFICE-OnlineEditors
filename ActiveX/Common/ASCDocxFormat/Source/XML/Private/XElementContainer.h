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
#ifndef XML_PRIVATE_XELEMENT_CONTAINER_INCLUDE_H_
#define XML_PRIVATE_XELEMENT_CONTAINER_INCLUDE_H_

#include <list>

#include "Filter/Element.h"
#include "XNamespaceContainer.h"

#include "../../../../../Common/DocxFormat/Source/Base/SmartPtr.h"

namespace XML
{
	class XNode;
	class XElement;
	class XName;

	namespace Private
	{
		class XNodeContainer;

		class XElementContainer
		{
		public:
			XElementContainer(const XNodeContainer& nodes);

		public:
			const bool empty() const;
			const size_t size() const;
			void push_back(const XElement& element);
			void Add(const XElement& element);

		public:
		
			typedef std::list<XNode>::iterator iterator;
			typedef std::list<XNode>::const_iterator const_iterator;

		public:
			XElementContainer const* const	operator->() const	{return this;}
			XElementContainer*				operator->()		{return this;}

			const bool exist(const XName& xname) const;
			XElement operator[] (const XName& xname);
			const XElement operator[] (const XName& xname) const;

			XElement get(const XName& xname, const std::string& value);
			const XElement get(const XName& xname, const std::string& value) const;

			const XNamespaceContainer usedNamespace() const;

		public:
			iterator begin();
			iterator end();
			const_iterator begin() const;
			const_iterator end() const;

		private:
			NSCommon::smart_ptr<std::list<XNode> >	m_container;
		};

	} 
} 

#endif // XML_PRIVATE_XELEMENT_CONTAINER_INCLUDE_H_