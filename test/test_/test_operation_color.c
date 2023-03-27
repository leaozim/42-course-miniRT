# include "../h_test.h"

void	test_create_color(void)
{
	double		r, g, b;
	t_color	color;
	int		i;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		r = rand_rgb();
		g = rand_rgb();
		b = rand_rgb();
		color = set_color(r, g, b);
		TEST_ASSERT_EQUAL_DOUBLE(r / 255, color.r);
		TEST_ASSERT_EQUAL_DOUBLE(g / 255, color.g);
		TEST_ASSERT_EQUAL_DOUBLE(b / 255, color.b);
		i++;
	}
}

void	test_add_color(void)
{
	double	r1, g1, b1;
	double	r2, g2, b2;
	t_color	colorA;
	t_color	colorB;
	t_color	sum;
	int 	i;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		r1 = rand_rgb();
		g1 = rand_rgb();
		b1 = rand_rgb();
		r2 = rand_rgb();
		g2 = rand_rgb();
		b2 = rand_rgb();
		colorA = set_color(r1, g1, b1);
		colorB = set_color(r2, g2, b2);
		sum = adding_color(colorA, colorB);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.r + colorB.r), sum.r);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.g + colorB.g), sum.g);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.b + colorB.b), sum.b);
		i++;
	}
}

void	multiply_color_scalar_correct(void)
{
	double		r, g, b, multiplier;
	int			i;
	t_color		color, result;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		r = rand_rgb();
		g = rand_rgb();
		b = rand_rgb();
		multiplier = rand_double();
		color = set_color(r, g, b);
		result = multiply_color_scalar(color, multiplier);
		TEST_ASSERT_EQUAL_DOUBLE(color.r * multiplier, result.r);
		TEST_ASSERT_EQUAL_DOUBLE(color.g * multiplier, result.g);
		TEST_ASSERT_EQUAL_DOUBLE(color.b * multiplier, result.b);
		i++;
	}
}

void	test_sub_color(void)
{
	double	r1, g1, b1;
	double	r2, g2, b2;
	t_color	colorA;
	t_color	colorB;
	t_color	sub;
	int 	i;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		r1 = rand_rgb();
		g1 = rand_rgb();
		b1 = rand_rgb();
		r2 = rand_rgb();
		g2 = rand_rgb();
		b2 = rand_rgb();
		colorA = set_color(r1, g1, b1);
		colorB = set_color(r2, g2, b2);
		sub = sub_color(colorA, colorB);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.r - colorB.r), sub.r);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.g - colorB.g), sub.g);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.b - colorB.b), sub.b);
		i++;
	}
}

void	test_mult_color(void)
{
	double	r1, g1, b1;
	double	r2, g2, b2;
	t_color	colorA;
	t_color	colorB;
	t_color	result;
	int 	i;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		r1 = rand_rgb();
		g1 = rand_rgb();
		b1 = rand_rgb();
		r2 = rand_rgb();
		g2 = rand_rgb();
		b2 = rand_rgb();
		colorA = set_color(r1, g1, b1);
		colorB = set_color(r2, g2, b2);
		result = multiply_color(colorA, colorB);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.r * colorB.r), result.r);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.g * colorB.g), result.g);
		TEST_ASSERT_EQUAL_DOUBLE((colorA.b * colorB.b), result.b);
		i++;
	}
}

void test_operation_color(void)
{
	RUN_TEST(test_create_color);
	RUN_TEST(test_add_color);
	RUN_TEST(test_sub_color);
	RUN_TEST(multiply_color_scalar_correct);
	RUN_TEST(test_mult_color);
}
