#include "rt.h"

float	plane_dist(float x_inter, t_ray r)
{
	t_vec3d new;
	float t_coef;

	if (ray.dir.x != 0)
	{
		t_coef = (x_inter - r.origin.x) / r.dir.x; //car on sait x_inter des le debut x=X (plane)
		if (t_coef >= 0)
			return (t_coef);
		else
			return (-1);
	}
	else
		return (-1);
}