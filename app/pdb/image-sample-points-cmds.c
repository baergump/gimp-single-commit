/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-2003 Spencer Kimball and Peter Mattis
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

/* NOTE: This file is auto-generated by pdbgen.pl. */

#include "config.h"

#include "stamp-pdbgen.h"

#include <gegl.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include "libgimpbase/gimpbase.h"

#include "pdb-types.h"

#include "core/gimpimage-sample-points.h"
#include "core/gimpimage.h"
#include "core/gimpparamspecs.h"
#include "core/gimpsamplepoint.h"

#include "gimppdb.h"
#include "gimppdberror.h"
#include "gimppdb-utils.h"
#include "gimpprocedure.h"
#include "internal-procs.h"

#include "gimp-intl.h"


static GimpValueArray *
image_add_sample_point_invoker (GimpProcedure         *procedure,
                                Gimp                  *gimp,
                                GimpContext           *context,
                                GimpProgress          *progress,
                                const GimpValueArray  *args,
                                GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpImage *image;
  gint position_x;
  gint position_y;
  guint sample_point = 0;

  image = g_value_get_object (gimp_value_array_index (args, 0));
  position_x = g_value_get_int (gimp_value_array_index (args, 1));
  position_y = g_value_get_int (gimp_value_array_index (args, 2));

  if (success)
    {
      if (position_x <= gimp_image_get_width  (image) &&
          position_y <= gimp_image_get_height (image))
        {
          GimpSamplePoint *sp;

          sp = gimp_image_add_sample_point_at_pos (image, position_x, position_y,
                                                   TRUE);
          sample_point = gimp_aux_item_get_id (GIMP_AUX_ITEM (sp));
        }
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_uint (gimp_value_array_index (return_vals, 1), sample_point);

  return return_vals;
}

static GimpValueArray *
image_delete_sample_point_invoker (GimpProcedure         *procedure,
                                   Gimp                  *gimp,
                                   GimpContext           *context,
                                   GimpProgress          *progress,
                                   const GimpValueArray  *args,
                                   GError               **error)
{
  gboolean success = TRUE;
  GimpImage *image;
  guint sample_point;

  image = g_value_get_object (gimp_value_array_index (args, 0));
  sample_point = g_value_get_uint (gimp_value_array_index (args, 1));

  if (success)
    {
      GimpSamplePoint *sp = gimp_pdb_image_get_sample_point (image, sample_point,
                                                             error);

      if (sp)
        gimp_image_remove_sample_point (image, sp, TRUE);
      else
        success = FALSE;
    }

  return gimp_procedure_get_return_values (procedure, success,
                                           error ? *error : NULL);
}

static GimpValueArray *
image_find_next_sample_point_invoker (GimpProcedure         *procedure,
                                      Gimp                  *gimp,
                                      GimpContext           *context,
                                      GimpProgress          *progress,
                                      const GimpValueArray  *args,
                                      GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpImage *image;
  guint sample_point;
  guint next_sample_point = 0;

  image = g_value_get_object (gimp_value_array_index (args, 0));
  sample_point = g_value_get_uint (gimp_value_array_index (args, 1));

  if (success)
    {
      GimpSamplePoint *sp = gimp_image_get_next_sample_point (image, sample_point,
                                                              &success);

      if (sp)
        next_sample_point = gimp_aux_item_get_id (GIMP_AUX_ITEM (sp));

      if (! success)
        g_set_error (error, GIMP_PDB_ERROR, GIMP_PDB_ERROR_INVALID_ARGUMENT,
                     _("Image '%s' (%d) does not contain sample point with ID %d"),
                     gimp_image_get_display_name (image),
                     gimp_image_get_id (image),
                     sample_point);
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_uint (gimp_value_array_index (return_vals, 1), next_sample_point);

  return return_vals;
}

static GimpValueArray *
image_get_sample_point_position_invoker (GimpProcedure         *procedure,
                                         Gimp                  *gimp,
                                         GimpContext           *context,
                                         GimpProgress          *progress,
                                         const GimpValueArray  *args,
                                         GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpImage *image;
  guint sample_point;
  gint position_x = 0;
  gint position_y = 0;

  image = g_value_get_object (gimp_value_array_index (args, 0));
  sample_point = g_value_get_uint (gimp_value_array_index (args, 1));

  if (success)
    {
      GimpSamplePoint *sp = gimp_pdb_image_get_sample_point (image, sample_point,
                                                             error);

      if (sp)
        gimp_sample_point_get_position (sp, &position_x, &position_y);
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    {
      g_value_set_int (gimp_value_array_index (return_vals, 1), position_x);
      g_value_set_int (gimp_value_array_index (return_vals, 2), position_y);
    }

  return return_vals;
}

void
register_image_sample_points_procs (GimpPDB *pdb)
{
  GimpProcedure *procedure;

  /*
   * gimp-image-add-sample-point
   */
  procedure = gimp_procedure_new (image_add_sample_point_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-image-add-sample-point");
  gimp_procedure_set_static_help (procedure,
                                  "Add a sample point to an image.",
                                  "This procedure adds a sample point to an image. It takes the input image and the position of the new sample points as parameters. It returns the sample point ID of the new sample point.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2016");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_image ("image",
                                                      "image",
                                                      "The image",
                                                      FALSE,
                                                      GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_int ("position-x",
                                                 "position x",
                                                 "The sample point's x-offset from left of image",
                                                 0, G_MAXINT32, 0,
                                                 GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_int ("position-y",
                                                 "position y",
                                                 "The sample point's y-offset from top of image",
                                                 0, G_MAXINT32, 0,
                                                 GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_uint ("sample-point",
                                                      "sample point",
                                                      "The new sample point",
                                                      1, G_MAXUINT32, 1,
                                                      GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-image-delete-sample-point
   */
  procedure = gimp_procedure_new (image_delete_sample_point_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-image-delete-sample-point");
  gimp_procedure_set_static_help (procedure,
                                  "Deletes a sample point from an image.",
                                  "This procedure takes an image and a sample point ID as input and removes the specified sample point from the specified image.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2016");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_image ("image",
                                                      "image",
                                                      "The image",
                                                      FALSE,
                                                      GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_uint ("sample-point",
                                                  "sample point",
                                                  "The ID of the sample point to be removed",
                                                  1, G_MAXUINT32, 1,
                                                  GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-image-find-next-sample-point
   */
  procedure = gimp_procedure_new (image_find_next_sample_point_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-image-find-next-sample-point");
  gimp_procedure_set_static_help (procedure,
                                  "Find next sample point on an image.",
                                  "This procedure takes an image and a sample point ID as input and finds the sample point ID of the successor of the given sample point ID in the image's sample point list. If the supplied sample point ID is 0, the procedure will return the first sample point. The procedure will return 0 if given the final sample point ID as an argument or the image has no sample points.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2016");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_image ("image",
                                                      "image",
                                                      "The image",
                                                      FALSE,
                                                      GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_uint ("sample-point",
                                                  "sample point",
                                                  "The ID of the current sample point (0 if first invocation)",
                                                  1, G_MAXUINT32, 1,
                                                  GIMP_PARAM_READWRITE | GIMP_PARAM_NO_VALIDATE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_uint ("next-sample-point",
                                                      "next sample point",
                                                      "The next sample point's ID",
                                                      1, G_MAXUINT32, 1,
                                                      GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-image-get-sample-point-position
   */
  procedure = gimp_procedure_new (image_get_sample_point_position_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-image-get-sample-point-position");
  gimp_procedure_set_static_help (procedure,
                                  "Get position of a sample point on an image.",
                                  "This procedure takes an image and a sample point ID as input and returns the position of the sample point relative to the top and left of the image.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2016");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_image ("image",
                                                      "image",
                                                      "The image",
                                                      FALSE,
                                                      GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_uint ("sample-point",
                                                  "sample point",
                                                  "The guide",
                                                  1, G_MAXUINT32, 1,
                                                  GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("position-x",
                                                     "position x",
                                                     "The sample point's x-offset relative to left of image",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_int ("position-y",
                                                     "position y",
                                                     "The sample point's y-offset relative to top of image",
                                                     G_MININT32, G_MAXINT32, 0,
                                                     GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);
}
