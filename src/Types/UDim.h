/*
 * Copyright (C) 2017 John M. Harris, Jr. <johnmh@openblox.org>
 *
 * This file is part of OpenBlox.
 *
 * OpenBlox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenBlox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 * along with OpenBlox. If not, see <https://www.gnu.org/licenses/>.
 */

#include "type/Type.h"

#include "oblibconfig.h"

#ifndef OB_TYPE_UDIM
#define OB_TYPE_UDIM

namespace OB{
	namespace Type{
		class UDim: public Type{
			public:
				UDim();
				UDim(double scale, double offset);
				UDim(std::string str);
				virtual ~UDim();

				double getScale();
				double getOffset();

				virtual bool equals(shared_ptr<Type> other);

				virtual std::string toString();

				static int lua_getScale(lua_State* L);
				static int lua_getOffset(lua_State* L);

				static int lua_eq(lua_State* L);

				static void register_lua_metamethods(lua_State* L);
				static void register_lua_methods(lua_State* L);
				static void register_lua_property_setters(lua_State* L);
				static void register_lua_property_getters(lua_State* L);

				DECLARE_TYPE();

				double scale;
				double offset;

		};

		shared_ptr<UDim> checkUDim(lua_State* L, int n, bool errIfNot = true, bool allowNil = true);
	}
}

#endif // OB_TYPE_UDIM


// Local Variables:
// mode: c++
// End:
