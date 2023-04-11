# include "../h_test.h"

void	hit_intersections_positive_t(void)
{
	t_shape			*shape;
	t_intersection	*i1;
	t_intersection	*i2;
	t_intersections	*list;
	t_intersection	*h;

	list = NULL;
	shape = create_sphere();
	i1 = create_intersection(1, shape);
	add_sorted(&list, ft_lstnew(i1));
	i2 = create_intersection(2, shape);
	add_sorted(&list, ft_lstnew(i2));
	h = hit(&list);
	TEST_ASSERT_EQUAL_PTR(h, i1);
	destroy_shape(shape);
	ft_lstclear(&list, free);
}

void	hit_intersections_negative_t(void)
{
	t_shape			*shape;
	t_intersection	*i1;
	t_intersection	*i2;
	t_intersections	*list;
	t_intersection	*h;

	list = NULL;
	shape = create_sphere();
	i1 = create_intersection(-1, shape);
	add_sorted(&list, ft_lstnew(i1));
	i2 = create_intersection(1, shape);
	add_sorted(&list, ft_lstnew(i2));
	h = hit(&list);
	TEST_ASSERT_EQUAL_PTR(h, i2);
	destroy_shape(shape);
	ft_lstclear(&list, free);
}

void	hit_intersections_nonnegative_t()
{
	t_shape			*shape;
	t_intersection	*i1, *i2, *i3, *i4;		
	t_intersections	*list;
	t_intersection	*h;

	list = NULL;
	shape = create_sphere();
	i1 = create_intersection(5, shape);
	add_sorted(&list, ft_lstnew(i1));
	i2 = create_intersection(7, shape);
	add_sorted(&list, ft_lstnew(i2));
	i3 = create_intersection(-3, shape);
	add_sorted(&list, ft_lstnew(i3));
	i4 = create_intersection(2, shape);
	add_sorted(&list, ft_lstnew(i4));
	h = hit(&list);
	TEST_ASSERT_EQUAL_PTR(h, i4);
	destroy_shape(shape);
	ft_lstclear(&list, free);
}

static void	hit_all_intersections_positive_t(void)
{
	t_shape			*shape;
	t_intersection	*i1;
	t_intersection	*i2;
	t_intersections	*list;
	t_intersection	*h;

	list = NULL;
	shape = create_sphere();
	i1 = create_intersection(-2, shape);
	add_sorted(&list, ft_lstnew(i1));
	i2 = create_intersection(-1, shape);
	add_sorted(&list, ft_lstnew(i2));
	h = hit(&list);
	TEST_ASSERT_EQUAL_PTR(h, NULL);
	ft_lstclear(&list, free);
	destroy_shape(shape);
}

void	test_hit(void)
{
	RUN_TEST(hit_intersections_positive_t);
	RUN_TEST(hit_intersections_negative_t);
	RUN_TEST(hit_all_intersections_positive_t);
	RUN_TEST(hit_intersections_nonnegative_t);
}