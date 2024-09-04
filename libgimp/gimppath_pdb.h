/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimppath_pdb.h
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

#if !defined (__GIMP_H_INSIDE__) && !defined (GIMP_COMPILATION)
#error "Only <libgimp/gimp.h> can be included directly."
#endif

#ifndef __GIMP_PATH_PDB_H__
#define __GIMP_PATH_PDB_H__

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


GimpPath*          gimp_path_new                       (GimpImage             *image,
                                                        const gchar           *name);
GimpPath*          gimp_path_new_from_text_layer       (GimpImage             *image,
                                                        GimpLayer             *layer);
GimpPath*          gimp_path_copy                      (GimpPath              *path);
gint*              gimp_path_get_strokes               (GimpPath              *path,
                                                        gint                  *num_strokes);
gdouble            gimp_path_stroke_get_length         (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                precision);
gboolean           gimp_path_stroke_get_point_at_dist  (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                dist,
                                                        gdouble                precision,
                                                        gdouble               *x_point,
                                                        gdouble               *y_point,
                                                        gdouble               *slope,
                                                        gboolean              *valid);
gboolean           gimp_path_remove_stroke             (GimpPath              *path,
                                                        gint                   stroke_id);
gboolean           gimp_path_stroke_close              (GimpPath              *path,
                                                        gint                   stroke_id);
gboolean           gimp_path_stroke_reverse            (GimpPath              *path,
                                                        gint                   stroke_id);
gboolean           gimp_path_stroke_translate          (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                off_x,
                                                        gdouble                off_y);
gboolean           gimp_path_stroke_scale              (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                scale_x,
                                                        gdouble                scale_y);
gboolean           gimp_path_stroke_rotate             (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                center_x,
                                                        gdouble                center_y,
                                                        gdouble                angle);
gboolean           gimp_path_stroke_flip               (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        GimpOrientationType    flip_type,
                                                        gdouble                axis);
gboolean           gimp_path_stroke_flip_free          (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                x1,
                                                        gdouble                y1,
                                                        gdouble                x2,
                                                        gdouble                y2);
GimpPathStrokeType gimp_path_stroke_get_points         (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gint                  *num_points,
                                                        gdouble              **controlpoints,
                                                        gboolean              *closed);
gint               gimp_path_stroke_new_from_points    (GimpPath              *path,
                                                        GimpPathStrokeType     type,
                                                        gint                   num_points,
                                                        const gdouble         *controlpoints,
                                                        gboolean               closed);
gdouble*           gimp_path_stroke_interpolate        (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                precision,
                                                        gint                  *num_coords,
                                                        gboolean              *closed);
gint               gimp_path_bezier_stroke_new_moveto  (GimpPath              *path,
                                                        gdouble                x0,
                                                        gdouble                y0);
gboolean           gimp_path_bezier_stroke_lineto      (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                x0,
                                                        gdouble                y0);
gboolean           gimp_path_bezier_stroke_conicto     (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                x0,
                                                        gdouble                y0,
                                                        gdouble                x1,
                                                        gdouble                y1);
gboolean           gimp_path_bezier_stroke_cubicto     (GimpPath              *path,
                                                        gint                   stroke_id,
                                                        gdouble                x0,
                                                        gdouble                y0,
                                                        gdouble                x1,
                                                        gdouble                y1,
                                                        gdouble                x2,
                                                        gdouble                y2);
gint               gimp_path_bezier_stroke_new_ellipse (GimpPath              *path,
                                                        gdouble                x0,
                                                        gdouble                y0,
                                                        gdouble                radius_x,
                                                        gdouble                radius_y,
                                                        gdouble                angle);
gboolean           gimp_path_import_from_file          (GimpImage             *image,
                                                        GFile                 *file,
                                                        gboolean               merge,
                                                        gboolean               scale,
                                                        gint                  *num_paths,
                                                        GimpPath            ***path);
gboolean           gimp_path_import_from_string        (GimpImage             *image,
                                                        const gchar           *string,
                                                        gint                   length,
                                                        gboolean               merge,
                                                        gboolean               scale,
                                                        gint                  *num_paths,
                                                        GimpPath            ***path);
gboolean           gimp_path_export_to_file            (GimpImage             *image,
                                                        GFile                 *file,
                                                        GimpPath              *path);
gchar*             gimp_path_export_to_string          (GimpImage             *image,
                                                        GimpPath              *path);


G_END_DECLS

#endif /* __GIMP_PATH_PDB_H__ */
