/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimp_pdb.c
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#include "config.h"

#include "stamp-pdbgen.h"

#include "gimp.h"


/**
 * SECTION: gimp
 * @title: gimp
 * @short_description: Main functions needed for building a GIMP plug-in.
 *
 * Main functions needed for building a GIMP plug-in.
 * This header includes all other GIMP Library headers.
 *
 * Also contains some miscellaneous procedures that don't fit in any
 * other category.
 **/


/**
 * gimp_version:
 *
 * Returns the host GIMP version.
 *
 * This procedure returns the version number of the currently running
 * GIMP.
 *
 * Returns: (transfer full): GIMP version number.
 *          The returned value must be freed with g_free().
 **/
gchar *
gimp_version (void)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gchar *version = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-version",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    version = GIMP_VALUES_DUP_STRING (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return version;
}

/**
 * gimp_getpid:
 *
 * Returns the PID of the host GIMP process.
 *
 * This procedure returns the process ID of the currently running GIMP.
 *
 * Returns: The PID.
 *
 * Since: 2.4
 **/
gint
gimp_getpid (void)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gint pid = 0;

  args = gimp_value_array_new_from_types (NULL,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-getpid",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    pid = GIMP_VALUES_GET_INT (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return pid;
}

/**
 * gimp_attach_parasite:
 * @parasite: The parasite to attach.
 *
 * Add a global parasite.
 *
 * This procedure attaches a global parasite. It has no return values.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.8
 **/
gboolean
gimp_attach_parasite (const GimpParasite *parasite)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PARASITE, parasite,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-attach-parasite",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_detach_parasite:
 * @name: The name of the parasite to detach.
 *
 * Removes a global parasite.
 *
 * This procedure detaches a global parasite from. It has no return
 * values.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.8
 **/
gboolean
gimp_detach_parasite (const gchar *name)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          G_TYPE_STRING, name,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-detach-parasite",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_get_parasite:
 * @name: The name of the parasite to find.
 *
 * Look up a global parasite.
 *
 * Finds and returns the global parasite that was previously attached.
 *
 * Returns: (transfer full): The found parasite.
 *
 * Since: 2.8
 **/
GimpParasite *
gimp_get_parasite (const gchar *name)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  GimpParasite *parasite = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          G_TYPE_STRING, name,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-get-parasite",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    parasite = GIMP_VALUES_DUP_PARASITE (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return parasite;
}

/**
 * gimp_get_parasite_list:
 *
 * List all parasites.
 *
 * Returns a list of all currently attached global parasites.
 *
 * Returns: (array zero-terminated=1) (transfer full):
 *          The names of currently attached parasites.
 *          The returned value must be freed with g_strfreev().
 *
 * Since: 2.8
 **/
gchar **
gimp_get_parasite_list (void)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gchar **parasites = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-get-parasite-list",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    parasites = GIMP_VALUES_DUP_STRV (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return parasites;
}

/**
 * gimp_temp_file:
 * @extension: The extension the file will have.
 *
 * Generates a unique temporary file.
 *
 * Generates a unique file using the temp path supplied in the user's
 * gimprc.
 *
 * Returns: (transfer full): The new temp file.
 **/
GFile *
gimp_temp_file (const gchar *extension)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  GFile *file = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          G_TYPE_STRING, extension,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-temp-file",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    file = GIMP_VALUES_DUP_FILE (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return file;
}
