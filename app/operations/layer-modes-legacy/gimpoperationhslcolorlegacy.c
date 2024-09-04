/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * gimpoperationcolormode.c
 * Copyright (C) 2008 Michael Natterer <mitch@gimp.org>
 *               2012 Ville Sokk <ville.sokk@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "config.h"

#include <gegl-plugin.h>
#include <cairo.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#include "libgimpcolor/gimpcolor.h"

#include "../operations-types.h"

#include "gimpoperationhslcolorlegacy.h"


static gboolean   gimp_operation_hsl_color_legacy_process (GeglOperation       *op,
                                                           void                *in,
                                                           void                *layer,
                                                           void                *mask,
                                                           void                *out,
                                                           glong                samples,
                                                           const GeglRectangle *roi,
                                                           gint                 level);


G_DEFINE_TYPE (GimpOperationHslColorLegacy, gimp_operation_hsl_color_legacy,
               GIMP_TYPE_OPERATION_LAYER_MODE)


static void
gimp_operation_hsl_color_legacy_class_init (GimpOperationHslColorLegacyClass *klass)
{
  GeglOperationClass          *operation_class  = GEGL_OPERATION_CLASS (klass);
  GimpOperationLayerModeClass *layer_mode_class = GIMP_OPERATION_LAYER_MODE_CLASS (klass);

  gegl_operation_class_set_keys (operation_class,
                                 "name",        "gimp:hsl-color-legacy",
                                 "description", "GIMP color mode operation",
                                 NULL);

  layer_mode_class->process = gimp_operation_hsl_color_legacy_process;
}

static void
gimp_operation_hsl_color_legacy_init (GimpOperationHslColorLegacy *self)
{
}

static gboolean
gimp_operation_hsl_color_legacy_process (GeglOperation       *op,
                                         void                *in_p,
                                         void                *layer_p,
                                         void                *mask_p,
                                         void                *out_p,
                                         glong                samples,
                                         const GeglRectangle *roi,
                                         gint                 level)
{
  GimpOperationLayerMode *layer_mode = (gpointer) op;
  gfloat                 *in         = in_p;
  gfloat                 *out        = out_p;
  gfloat                 *layer      = layer_p;
  gfloat                 *mask       = mask_p;
  gfloat                  opacity    = layer_mode->opacity;

  while (samples--)
    {
      gfloat layer_hsl[3], out_hsl[3];
      gfloat out_rgb[3];
      gfloat comp_alpha, new_alpha;

      comp_alpha = MIN (in[ALPHA], layer[ALPHA]) * opacity;
      if (mask)
        comp_alpha *= *mask;

      new_alpha = in[ALPHA] + (1.0f - in[ALPHA]) * comp_alpha;

      if (comp_alpha && new_alpha)
        {
          gint   b;
          gfloat ratio = comp_alpha / new_alpha;

          /* TODO: shouldn't these conversions be processed in image space, or
           * doesn't it matter?
           */
          babl_process (babl_fish (babl_format ("R'G'B' float"), babl_format ("HSL float")),
                        layer, layer_hsl, 1);
          babl_process (babl_fish (babl_format ("R'G'B' float"), babl_format ("HSL float")),
                        in, out_hsl, 1);

          out_hsl[0] = layer_hsl[0];
          out_hsl[1] = layer_hsl[1];
          babl_process (babl_fish (babl_format ("HSL float"), babl_format ("R'G'B' float")),
                        out_hsl, out_rgb, 1);

          for (b = RED; b < ALPHA; b++)
            out[b] = out_rgb[b] * ratio + in[b] * (1.0f - ratio);
        }
      else
        {
          gint b;

          for (b = RED; b < ALPHA; b++)
            {
              out[b] = in[b];
            }
        }

      out[ALPHA] = in[ALPHA];

      in    += 4;
      layer += 4;
      out   += 4;

      if (mask)
        mask++;
    }

  return TRUE;
}
