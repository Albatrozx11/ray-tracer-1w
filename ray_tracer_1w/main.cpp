#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"

color ray_color(const ray& r) {
	auto ray_direction_scaled = unit_vector(r.direction());
	auto a = 0.5 * (1 + ray_direction_scaled.y());
	return (1 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {
	//image width and aspect ratio
	int image_width = 400;
	double aspect_ratio = 16.0 / 9.0;

	//calculate image height from image width and  aspect ratio
	int image_height = int(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	//calculate viewport width from viewport height and aspect ratio calculated
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * (double(image_width) / image_height);

	//camera center and focal length(distance to viewport from camera center)
	auto camera_center = point3(0, 0, 0);
	auto focal_length = 1;

	//viewport horizontal and vertical vectors
	auto viewport_u = vec3(viewport_width, 0, 0);
	auto viewport_v = vec3(0, -viewport_height, 0);

	//viewport horizontal and vertical delta vectors(pixel spacing)
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	//viewport upper left location
	auto viewport_upper_left = camera_center - point3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;

	//pixel 0 location P(0,0)
	auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
	
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for (int j = 0; j < image_height; j++) {
		std::clog << "\rScanline Remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++) {

			auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
			auto ray_direction = pixel_center - camera_center;

			ray r(camera_center, ray_direction);
			

			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}

	std::clog << "\rDone.                   \n";

	return 0;
}