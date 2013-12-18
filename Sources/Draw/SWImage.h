/*
 Copyright (c) 2013 yvt
 
 This file is part of OpenSpades.
 
 OpenSpades is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 OpenSpades is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with OpenSpades.  If not, see <http://www.gnu.org/licenses/>.
 
 */

#pragma once

#include <Client/IImage.h>
#include <Core/Bitmap.h>
#include <map>

namespace spades {
	namespace draw {
		class SWImage: public client::IImage {
			Handle<Bitmap> rawBmp;
			
			float w, h;
		protected:
			virtual ~SWImage();
		public:
			SWImage(Bitmap *bmp);
			
			Bitmap *GetRawBitmap() { return rawBmp; }
			
			virtual float GetWidth() { return w; }
			virtual float GetHeight() { return h; }
		};
		
		class SWImageManager {
			// unordered_map is preferred, but not supported by MSVC2010
			std::map<std::string, SWImage *> images;
		public:
			SWImageManager() {}
			~SWImageManager();
			
			SWImage *RegisterImage(const std::string&);
			SWImage *CreateImage(Bitmap *);
		};
	}
}
