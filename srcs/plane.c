#include "rt.h"

float	plane_dist(t_obj obj, t_ray r)
{
	t_vec3d new_inter_plane;
	float t_coef;

	t_coef = -1;
	new_inter_plane = rota_vect(obj.transform.transl, obj.transform.rot);
	if (r.dir.x != 0)
	{
		if (obj.transform.transl.x != 0) //if x != 0, x plane = X
			t_coef = (new_inter_plane.x - r.origin.x) / r.dir.x;
		else if (obj.transform.transl.y != 0)
			t_coef = (new_inter_plane.y - r.origin.y) / r.dir.y;
		else if (obj.transform.transl.z != 0)
			t_coef = (new_inter_plane.z - r.origin.z) / r.dir.z;
		if (t_coef >= 0)
			return (t_coef);
		else
			return (-1);
	}
	else
		return (-1);
}

t_vec3d		plane_normal_vec(t_no no)
{
	t_vec3d ret;


	ret.x = 1; //if x != 0
	ret.y = 0;
	ret.z = 0;
	ret.w = 1;
	if (no.obj.transform.transl.x == 0 && no.obj.transform.transl.y != 0)
	{
		ret.x = 0;
		ret.y = 1;
		ret.z = 0;
		ret.w = 1;
	}
	else if (no.obj.transform.transl.z != 0)
	{
		ret.x = 0;
		ret.y = 0;
		ret.z = 1;
		ret.w = 1;
	}
	return (ret);
}