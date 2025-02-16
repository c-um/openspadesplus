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

#include <Core/Debug.h>

#include "GLSettings.h"

DEFINE_SPADES_SETTING(r_blitFramebuffer, "1");
DEFINE_SPADES_SETTING(r_bloom, "0");
DEFINE_SPADES_SETTING(r_cameraBlur, "0");
DEFINE_SPADES_SETTING(r_colorCorrection, "0");
DEFINE_SPADES_SETTING(r_debugTiming, "0");
DEFINE_SPADES_SETTING(r_debugTimingOutputScreen, "1");
DEFINE_SPADES_SETTING(r_debugTimingOutputLog, "0");
DEFINE_SPADES_SETTING(r_debugTimingAverage, "1");
DEFINE_SPADES_SETTING(r_debugTimingGPUTime, "1");
DEFINE_SPADES_SETTING(r_debugTimingOutputBarScale, "2");
DEFINE_SPADES_SETTING(r_debugTimingFlush, "0");
DEFINE_SPADES_SETTING(r_debugTimingFillGap, "0");
DEFINE_SPADES_SETTING(r_depthOfField, "0");
DEFINE_SPADES_SETTING(r_depthOfFieldMaxCoc, "0.01");
DEFINE_SPADES_SETTING(r_depthPrepass, "1");
DEFINE_SPADES_SETTING(r_dlights, "0");
DEFINE_SPADES_SETTING(r_exposureValue, "0");
DEFINE_SPADES_SETTING(r_fogShadow, "0");
DEFINE_SPADES_SETTING(r_fxaa, "0");
DEFINE_SPADES_SETTING(r_hdr, "0");
DEFINE_SPADES_SETTING(r_hdrAutoExposureMin, "-1.5");
DEFINE_SPADES_SETTING(r_hdrAutoExposureMax, "0.5");
DEFINE_SPADES_SETTING(r_hdrAutoExposureSpeed, "1");
DEFINE_SPADES_SETTING(r_hdrGamma, "2.2");
DEFINE_SPADES_SETTING(r_highPrec, "1");
DEFINE_SPADES_SETTING(r_lens, "0");
DEFINE_SPADES_SETTING(r_lensFlare, "0");
DEFINE_SPADES_SETTING(r_lensFlareDynamic, "0");
DEFINE_SPADES_SETTING(r_mapSoftShadow, "0");
DEFINE_SPADES_SETTING(r_maxAnisotropy, "8");
DEFINE_SPADES_SETTING(r_modelShadows, "0");
DEFINE_SPADES_SETTING(r_multisamples, "0");
DEFINE_SPADES_SETTING(r_occlusionQuery, "0");
DEFINE_SPADES_SETTING(r_optimizedVoxelModel, "1");
DEFINE_SPADES_SETTING(r_physicalLighting, "0");
DEFINE_SPADES_SETTING(r_radiosity, "0");
DEFINE_SPADES_SETTING(r_saturation, "1");
DEFINE_SPADES_SETTING(r_scale, "1");
DEFINE_SPADES_SETTING(r_scaleFilter, "1");
DEFINE_SPADES_SETTING(r_shadowMapSize, "2048");
DEFINE_SPADES_SETTING(r_sharpen, "0");
DEFINE_SPADES_SETTING(r_softParticles, "0");
DEFINE_SPADES_SETTING(r_sparseShadowMaps, "1");
DEFINE_SPADES_SETTING(r_srgb, "0");
DEFINE_SPADES_SETTING(r_srgb2D, "1");
DEFINE_SPADES_SETTING(r_ssao, "0");
DEFINE_SPADES_SETTING(r_temporalAA, "0");
DEFINE_SPADES_SETTING(r_water, "0");

namespace spades {
	namespace draw {
		GLSettings::GLSettings() {}

		void GLSettings::ValidateSettings() {
			if (this->r_fogShadow.operator int() == 2 && !this->ShouldUseFogFilter2()) {
				SPLog("`r_fogShadow 2` is ignored because `r_radiosity` is disabled");
			}
		}

		bool GLSettings::ShouldUseFogFilter2() {
			return this->r_fogShadow.operator int() == 2 && !!this->r_radiosity.operator int();
		}
    } // namespace draw
} // namespace spades
