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

void	test_view_transformation(void)
{
	RUN_TEST(test_default_orientation);
}