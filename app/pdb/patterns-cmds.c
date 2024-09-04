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

#include <string.h>

#include <gegl.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include "libgimpbase/gimpbase.h"

#include "pdb-types.h"

#include "core/gimp.h"
#include "core/gimpcontainer-filter.h"
#include "core/gimpcontext.h"
#include "core/gimpdatafactory.h"
#include "core/gimpparamspecs.h"
#include "core/gimppattern.h"
#include "core/gimptempbuf.h"

#include "gimppdb.h"
#include "gimppdb-utils.h"
#include "gimpprocedure.h"
#include "internal-procs.h"


static GimpValueArray *
patterns_refresh_invoker (GimpProcedure         *procedure,
                          Gimp                  *gimp,
                          GimpContext           *context,
                          GimpProgress          *progress,
                          const GimpValueArray  *args,
                          GError               **error)
{
  gimp_data_factory_data_refresh (gimp->pattern_factory, context);

  return gimp_procedure_get_return_values (procedure, TRUE, NULL);
}

static GimpValueArray *
patterns_get_list_invoker (GimpProcedure         *procedure,
                           Gimp                  *gimp,
                           GimpContext           *context,
                           GimpProgress          *progress,
                           const GimpValueArray  *args,
                           GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  const gchar *filter;
  gchar **pattern_list = NULL;

  filter = g_value_get_string (gimp_value_array_index (args, 0));

  if (success)
    {
      pattern_list = gimp_container_get_filtered_name_array (gimp_data_factory_get_container (gimp->pattern_factory),
                                                             filter);
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_take_boxed (gimp_value_array_index (return_vals, 1), pattern_list);

  return return_vals;
}

void
register_patterns_procs (GimpPDB *pdb)
{
  GimpProcedure *procedure;

  /*
   * gimp-patterns-refresh
   */
  procedure = gimp_procedure_new (patterns_refresh_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-patterns-refresh");
  gimp_procedure_set_static_help (procedure,
                                  "Refresh current patterns. This function always succeeds.",
                                  "This procedure retrieves all patterns currently in the user's pattern path and updates all pattern dialogs accordingly.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Michael Natterer <mitch@gimp.org>",
                                         "Michael Natterer",
                                         "2002");
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-patterns-get-list
   */
  procedure = gimp_procedure_new (patterns_get_list_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-patterns-get-list");
  gimp_procedure_set_static_help (procedure,
                                  "Retrieve a complete listing of the available patterns.",
                                  "This procedure returns a complete listing of available GIMP patterns. Each name returned can be used as input to the 'gimp-context-set-pattern'.",
                                  NULL);
  gimp_procedure_set_static_attribution (procedure,
                                         "Spencer Kimball & Peter Mattis",
                                         "Spencer Kimball & Peter Mattis",
                                         "1995-1996");
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("filter",
                                                       "filter",
                                                       "An optional regular expression used to filter the list",
                                                       FALSE, TRUE, FALSE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_boxed ("pattern-list",
                                                       "pattern list",
                                                       "The list of pattern names",
                                                       G_TYPE_STRV,
                                                       GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);
}
