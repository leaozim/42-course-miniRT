# include "../h_test.h"

void	test_default_orientation(void)
{
	t_matrix	identity, view;
	t_point		from, to;
	t_vector	up;

	from = create_point(0, 0, 0);
	to = create_point(0, 0, -1);
	up = create_vector(0, 1, 0);
	identity = create_identity_matrix();
	view = view_transformation(from, to, up);
	TEST_ASSERT_TRUE(is_equal_matrix(identity, view));
}

void	test_trans_positive_z_direction(void)
{
	t_matrix	scal, view;
	t_point		from, to;
	t_vector	up;

	from = create_point(0, 0, 0);
	to = create_point(0, 0, 1);
	up = create_vector(0, 1, 0);
	scal = scaling(-1, 1, -1);
	view = view_transformation(from, to, up);
	TEST_ASSERT_TRUE(is_equal_matrix(scal, view));
}

void	test_moves_world(void)
{
	t_matrix	trans, view;
	t_point		from, to;
	t_vector	up;

	from = create_point(0, 0, 8);
	to = create_point(0, 0, 0);
	up = create_vector(0, 1, 0);
	trans = translation(0, 0, -8);
	view = view_transformation(from, to, up);
	TEST_ASSERT_TRUE(is_equal_matrix(trans, view));	
}

void	test_arbitrary_view_transformation(void)
{
	t_matrix	view;
	t_point		from, to;
	t_vector	up;

	t_matrix m = {4,{	
		{-0.50709, 0.50709, 0.67612, -2.36643},
		{0.76772,  0.60609, 0.12122, -2.82843},
		{-0.35857, 0.59761,-0.71714, 0.00000},
		{0.00000,  0.00000, 0.00000, 1.00000}}};
	from = create_point(1, 3, 2);
	to = create_point(4, -2, 8);
	up = create_vector(1, 1, 0);
	view = view_transformation(from, to, up);
	TEST_ASSERT_TRUE(is_equal_matrix(m, view));
}

void	test_view_transformation(void)
{
	RUN_TEST(test_default_orientation);
	RUN_TEST(test_trans_positive_z_direction);
	RUN_TEST(test_moves_world);
	RUN_TEST(test_arbitrary_view_transformation);
}