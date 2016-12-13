#include "rt.h"

float    plane_dist(t_obj obj, t_ray r)
{
    float	t_coef;
    float	normal_to_ray;
    t_vec3d vect_to_point;

    t_coef = -1;
    normal_to_ray = vector_dot(obj.normal, r.dir);

    if (normal_to_ray != 0)
    {
    	vect_to_point = vector_sub(obj.transform.transl, r.origin);
    	t_coef = vector_dot(obj.normal, vect_to_point) / normal_to_ray;
    }
    if (t_coef > 0)
        return (t_coef);
    else
        return (-1);
}
