void	mechanical_turk(t_stack **a, t_stack **b, int ins_ind_b, t_cost cost)
{
	int	min_cost;
	int	best_index;
	int	i;
	t_cost	best_cost;

	min_cost = INT_MAX;
	best_index = -1;
	pb(a, b);
	pb(a, b);

	while ((*a)->size > 0)
	{
		while (i < (*a)->size)
		{
			ins_ind_b = ind_insert_find(*b, ind_value_get(*a, i));
			cost_ = total_cost_calculation(*a, *b, i, ins_ind_b);
			if (cost.total_cost < min_cost)
			{
				min_cost = cost.total_cost;
				best_index = i;
				best_cost = cost;
			}
			i++;
		}
		moves_execution(a, b, best_index, best_cost);
		pb(a, b);
	}
	while ((*b)->size > 0)
		pa(a, b);
}
