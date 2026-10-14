# Library Checker 対応状況

[Library Checker](https://judge.yosupo.jp/) の各問題に対応するライブラリの作成状況。
上から順番に作成する（並びはサイトのカテゴリ順 = [categories.toml](https://github.com/yosupo06/library-checker-problems/blob/master/categories.toml)）。

- ✅ : ライブラリ作成済み・verify 済み
- ⬜ : 未着手

既存のライブラリ（`graph/dsu.hpp`, `graph/dijkstra.hpp`）は fastio 導入前に作ったもので、速度面の見直しはまだしていない。

**進捗: 41 / 235**

## Sample

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ✅ | [A + B](https://judge.yosupo.jp/problem/aplusb) (`aplusb`) | [`io/fastio.hpp`](io/fastio.hpp) | [`test/aplusb.test.cpp`](test/aplusb.test.cpp) |
| ✅ | [Many A + B](https://judge.yosupo.jp/problem/many_aplusb) (`many_aplusb`) | [`io/fastio.hpp`](io/fastio.hpp) | [`test/many_aplusb.test.cpp`](test/many_aplusb.test.cpp) |
| ✅ | [Many A + B (128 bit)](https://judge.yosupo.jp/problem/many_aplusb_128bit) (`many_aplusb_128bit`) | [`io/fastio.hpp`](io/fastio.hpp) | [`test/many_aplusb_128bit.test.cpp`](test/many_aplusb_128bit.test.cpp) |

## Data Structure

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ✅ | [Associative Array](https://judge.yosupo.jp/problem/associative_array) (`associative_array`) | [`data_structure/hash_map.hpp`](data_structure/hash_map.hpp) | [`test/associative_array.test.cpp`](test/associative_array.test.cpp) |
| ✅ | [Predecessor Problem](https://judge.yosupo.jp/problem/predecessor_problem) (`predecessor_problem`) | [`data_structure/fast_set.hpp`](data_structure/fast_set.hpp) | [`test/predecessor_problem.test.cpp`](test/predecessor_problem.test.cpp) |
| ✅ | [Ordered Set](https://judge.yosupo.jp/problem/ordered_set) (`ordered_set`) | [`data_structure/ordered_set.hpp`](data_structure/ordered_set.hpp) | [`test/ordered_set.test.cpp`](test/ordered_set.test.cpp) |
| ✅ | [Double-Ended Priority Queue](https://judge.yosupo.jp/problem/double_ended_priority_queue) (`double_ended_priority_queue`) | [`data_structure/interval_heap.hpp`](data_structure/interval_heap.hpp) | [`test/double_ended_priority_queue.test.cpp`](test/double_ended_priority_queue.test.cpp) |
| ✅ | [Unionfind](https://judge.yosupo.jp/problem/unionfind) (`unionfind`) | [`graph/dsu.hpp`](graph/dsu.hpp) | [`test/unionfind.test.cpp`](test/unionfind.test.cpp) |
| ✅ | [Unionfind with Potential](https://judge.yosupo.jp/problem/unionfind_with_potential) (`unionfind_with_potential`) | [`data_structure/potentialized_unionfind.hpp`](data_structure/potentialized_unionfind.hpp) | [`test/unionfind_with_potential.test.cpp`](test/unionfind_with_potential.test.cpp) |
| ✅ | [Unionfind with Potential (Non-Commutative Group)](https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group) (`unionfind_with_potential_non_commutative_group`) | [`data_structure/potentialized_unionfind.hpp`](data_structure/potentialized_unionfind.hpp) | [`test/unionfind_with_potential_non_commutative_group.test.cpp`](test/unionfind_with_potential_non_commutative_group.test.cpp) |
| ✅ | [Range Parallel Unionfind](https://judge.yosupo.jp/problem/range_parallel_unionfind) (`range_parallel_unionfind`) | [`data_structure/range_parallel_unionfind.hpp`](data_structure/range_parallel_unionfind.hpp) | [`test/range_parallel_unionfind.test.cpp`](test/range_parallel_unionfind.test.cpp), [`test/range_parallel_unionfind_online.test.cpp`](test/range_parallel_unionfind_online.test.cpp) |
| ✅ | [Static Range Sum](https://judge.yosupo.jp/problem/static_range_sum) (`static_range_sum`) | [`data_structure/cumulative_sum.hpp`](data_structure/cumulative_sum.hpp) | [`test/static_range_sum.test.cpp`](test/static_range_sum.test.cpp) |
| ✅ | [Static RMQ](https://judge.yosupo.jp/problem/staticrmq) (`staticrmq`) | [`data_structure/static_rmq.hpp`](data_structure/static_rmq.hpp), [`data_structure/sparse_table.hpp`](data_structure/sparse_table.hpp) | [`test/staticrmq.test.cpp`](test/staticrmq.test.cpp), [`test/staticrmq_sparse_table.test.cpp`](test/staticrmq_sparse_table.test.cpp) |
| ✅ | [Point Add Range Sum](https://judge.yosupo.jp/problem/point_add_range_sum) (`point_add_range_sum`) | [`data_structure/fenwick_tree.hpp`](data_structure/fenwick_tree.hpp) | [`test/point_add_range_sum.test.cpp`](test/point_add_range_sum.test.cpp) |
| ✅ | [Point Set Range Composite](https://judge.yosupo.jp/problem/point_set_range_composite) (`point_set_range_composite`) | [`data_structure/segment_tree.hpp`](data_structure/segment_tree.hpp) | [`test/point_set_range_composite.test.cpp`](test/point_set_range_composite.test.cpp) |
| ✅ | [Point Set Range Composite (Large Array)](https://judge.yosupo.jp/problem/point_set_range_composite_large_array) (`point_set_range_composite_large_array`) | [`data_structure/dynamic_segment_tree.hpp`](data_structure/dynamic_segment_tree.hpp) | [`test/point_set_range_composite_large_array.test.cpp`](test/point_set_range_composite_large_array.test.cpp) |
| ✅ | [Range Affine Point Get](https://judge.yosupo.jp/problem/range_affine_point_get) (`range_affine_point_get`) | [`data_structure/dual_segment_tree.hpp`](data_structure/dual_segment_tree.hpp) | [`test/range_affine_point_get.test.cpp`](test/range_affine_point_get.test.cpp) |
| ✅ | [Range Affine Range Sum](https://judge.yosupo.jp/problem/range_affine_range_sum) (`range_affine_range_sum`) | [`data_structure/lazy_segment_tree.hpp`](data_structure/lazy_segment_tree.hpp) | [`test/range_affine_range_sum.test.cpp`](test/range_affine_range_sum.test.cpp) |
| ✅ | [Range Affine Range Sum (Large Array)](https://judge.yosupo.jp/problem/range_affine_range_sum_large_array) (`range_affine_range_sum_large_array`) | [`data_structure/dynamic_lazy_segment_tree.hpp`](data_structure/dynamic_lazy_segment_tree.hpp) | [`test/range_affine_range_sum_large_array.test.cpp`](test/range_affine_range_sum_large_array.test.cpp) |
| ✅ | [Persistent Range Affine Range Sum](https://judge.yosupo.jp/problem/persistent_range_affine_range_sum) (`persistent_range_affine_range_sum`) | [`data_structure/persistent_lazy_segment_tree.hpp`](data_structure/persistent_lazy_segment_tree.hpp) | [`test/persistent_range_affine_range_sum.test.cpp`](test/persistent_range_affine_range_sum.test.cpp) |
| ✅ | [Range Set Range Composite](https://judge.yosupo.jp/problem/range_set_range_composite) (`range_set_range_composite`) | [`data_structure/range_assign_segment_tree.hpp`](data_structure/range_assign_segment_tree.hpp) | [`test/range_set_range_composite.test.cpp`](test/range_set_range_composite.test.cpp) |
| ✅ | [Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum) (`range_chmin_chmax_add_range_sum`) | [`data_structure/segment_tree_beats.hpp`](data_structure/segment_tree_beats.hpp) | [`test/range_chmin_chmax_add_range_sum.test.cpp`](test/range_chmin_chmax_add_range_sum.test.cpp) |
| ✅ | [Range Kth Smallest](https://judge.yosupo.jp/problem/range_kth_smallest) (`range_kth_smallest`) | [`data_structure/wavelet_matrix.hpp`](data_structure/wavelet_matrix.hpp) | [`test/range_kth_smallest.test.cpp`](test/range_kth_smallest.test.cpp) |
| ✅ | [Point Set Range Sort Range Composite](https://judge.yosupo.jp/problem/point_set_range_sort_range_composite) (`point_set_range_sort_range_composite`) | [`data_structure/sortable_segment_tree.hpp`](data_structure/sortable_segment_tree.hpp) | [`test/point_set_range_sort_range_composite.test.cpp`](test/point_set_range_sort_range_composite.test.cpp) |
| ✅ | [Range Reverse Range Sum](https://judge.yosupo.jp/problem/range_reverse_range_sum) (`range_reverse_range_sum`) | [`data_structure/dynamic_sequence.hpp`](data_structure/dynamic_sequence.hpp) | [`test/range_reverse_range_sum.test.cpp`](test/range_reverse_range_sum.test.cpp) |
| ✅ | [Dynamic Sequence Range Affine Range Sum](https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum) (`dynamic_sequence_range_affine_range_sum`) | [`data_structure/dynamic_sequence.hpp`](data_structure/dynamic_sequence.hpp) | [`test/dynamic_sequence_range_affine_range_sum.test.cpp`](test/dynamic_sequence_range_affine_range_sum.test.cpp) |
| ✅ | [Range Linear Add Range Min](https://judge.yosupo.jp/problem/range_linear_add_range_min) (`range_linear_add_range_min`) | [`data_structure/linear_add_min_segment_tree.hpp`](data_structure/linear_add_min_segment_tree.hpp) | [`test/range_linear_add_range_min.test.cpp`](test/range_linear_add_range_min.test.cpp) |
| ✅ | [Set Xor-Min](https://judge.yosupo.jp/problem/set_xor_min) (`set_xor_min`) | [`data_structure/binary_trie.hpp`](data_structure/binary_trie.hpp) | [`test/set_xor_min.test.cpp`](test/set_xor_min.test.cpp) |
| ✅ | [Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min) (`line_add_get_min`) | [`data_structure/li_chao_tree.hpp`](data_structure/li_chao_tree.hpp) | [`test/line_add_get_min.test.cpp`](test/line_add_get_min.test.cpp) |
| ✅ | [Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min) (`segment_add_get_min`) | [`data_structure/li_chao_tree.hpp`](data_structure/li_chao_tree.hpp) | [`test/segment_add_get_min.test.cpp`](test/segment_add_get_min.test.cpp), [`test/segment_add_get_min_offline.test.cpp`](test/segment_add_get_min_offline.test.cpp) |
| ✅ | [Queue Operate All Composite](https://judge.yosupo.jp/problem/queue_operate_all_composite) (`queue_operate_all_composite`) | [`data_structure/foldable_queue.hpp`](data_structure/foldable_queue.hpp) | [`test/queue_operate_all_composite.test.cpp`](test/queue_operate_all_composite.test.cpp) |
| ✅ | [Deque Operate All Composite](https://judge.yosupo.jp/problem/deque_operate_all_composite) (`deque_operate_all_composite`) | [`data_structure/foldable_deque.hpp`](data_structure/foldable_deque.hpp) | [`test/deque_operate_all_composite.test.cpp`](test/deque_operate_all_composite.test.cpp) |
| ✅ | [Static Range Frequency](https://judge.yosupo.jp/problem/static_range_frequency) (`static_range_frequency`) | [`data_structure/static_range_frequency.hpp`](data_structure/static_range_frequency.hpp) | [`test/static_range_frequency.test.cpp`](test/static_range_frequency.test.cpp) |
| ✅ | [Static Range Count Distinct](https://judge.yosupo.jp/problem/static_range_count_distinct) (`static_range_count_distinct`) | [`data_structure/static_range_count_distinct.hpp`](data_structure/static_range_count_distinct.hpp) | [`test/static_range_count_distinct.test.cpp`](test/static_range_count_distinct.test.cpp) |
| ✅ | [Static Range Mode Query](https://judge.yosupo.jp/problem/static_range_mode_query) (`static_range_mode_query`) | [`data_structure/static_range_mode.hpp`](data_structure/static_range_mode.hpp) | [`test/static_range_mode_query.test.cpp`](test/static_range_mode_query.test.cpp) |
| ✅ | [Static Range LIS Query](https://judge.yosupo.jp/problem/static_range_lis_query) (`static_range_lis_query`) | [`data_structure/static_range_lis.hpp`](data_structure/static_range_lis.hpp) | [`test/static_range_lis_query.test.cpp`](test/static_range_lis_query.test.cpp) |
| ✅ | [Static Range Inversions Query](https://judge.yosupo.jp/problem/static_range_inversions_query) (`static_range_inversions_query`) | [`data_structure/static_range_inversions.hpp`](data_structure/static_range_inversions.hpp) | [`test/static_range_inversions_query.test.cpp`](test/static_range_inversions_query.test.cpp) |
| ✅ | [Point Set Range Frequency](https://judge.yosupo.jp/problem/point_set_range_frequency) (`point_set_range_frequency`) | [`data_structure/dynamic_range_frequency.hpp`](data_structure/dynamic_range_frequency.hpp) | [`test/point_set_range_frequency.test.cpp`](test/point_set_range_frequency.test.cpp) |
| ✅ | [Rectangle Sum](https://judge.yosupo.jp/problem/rectangle_sum) (`rectangle_sum`) | [`data_structure/static_rectangle_sum.hpp`](data_structure/static_rectangle_sum.hpp) | [`test/rectangle_sum.test.cpp`](test/rectangle_sum.test.cpp) |
| ✅ | [Point Add Rectangle Sum](https://judge.yosupo.jp/problem/point_add_rectangle_sum) (`point_add_rectangle_sum`) | [`data_structure/static_rectangle_sum.hpp`](data_structure/static_rectangle_sum.hpp) | [`test/point_add_rectangle_sum.test.cpp`](test/point_add_rectangle_sum.test.cpp) |
| ⬜ | [Rectangle Add Point Get](https://judge.yosupo.jp/problem/rectangle_add_point_get) (`rectangle_add_point_get`) |  |  |
| ⬜ | [Static Rectangle Add Rectangle Sum](https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum) (`static_rectangle_add_rectangle_sum`) |  |  |
| ⬜ | [Dynamic Point Rectangle Affine Rectangle Sum](https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum) (`dynamic_point_set_rectangle_affine_rectangle_sum`) |  |  |
| ⬜ | [Area of Union of Rectangles](https://judge.yosupo.jp/problem/area_of_union_of_rectangles) (`area_of_union_of_rectangles`) |  |  |
| ⬜ | [Persistent Queue](https://judge.yosupo.jp/problem/persistent_queue) (`persistent_queue`) |  |  |
| ⬜ | [Persistent Unionfind](https://judge.yosupo.jp/problem/persistent_unionfind) (`persistent_unionfind`) |  |  |

## Graph

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Cycle Detection (Directed)](https://judge.yosupo.jp/problem/cycle_detection) (`cycle_detection`) |  |  |
| ⬜ | [Cycle Detection (Undirected)](https://judge.yosupo.jp/problem/cycle_detection_undirected) (`cycle_detection_undirected`) |  |  |
| ✅ | [Shortest Path](https://judge.yosupo.jp/problem/shortest_path) (`shortest_path`) | [`graph/dijkstra.hpp`](graph/dijkstra.hpp) | [`test/dijkstra.test.cpp`](test/dijkstra.test.cpp) |
| ⬜ | [Strongly Connected Components](https://judge.yosupo.jp/problem/scc) (`scc`) |  |  |
| ⬜ | [Strongly Connected Components (Incremental)](https://judge.yosupo.jp/problem/incremental_scc) (`incremental_scc`) |  |  |
| ⬜ | [K-Shortest Walk](https://judge.yosupo.jp/problem/k_shortest_walk) (`k_shortest_walk`) |  |  |
| ⬜ | [Two-Edge-Connected Components](https://judge.yosupo.jp/problem/two_edge_connected_components) (`two_edge_connected_components`) |  |  |
| ⬜ | [Three-Edge-Connected Components](https://judge.yosupo.jp/problem/three_edge_connected_components) (`three_edge_connected_components`) |  |  |
| ⬜ | [Biconnected Components](https://judge.yosupo.jp/problem/biconnected_components) (`biconnected_components`) |  |  |
| ⬜ | [Connected Components of Complement Graph](https://judge.yosupo.jp/problem/connected_components_of_complement_graph) (`connected_components_of_complement_graph`) |  |  |
| ⬜ | [Eulerian Trail (Directed)](https://judge.yosupo.jp/problem/eulerian_trail_directed) (`eulerian_trail_directed`) |  |  |
| ⬜ | [Eulerian Trail (Undirected)](https://judge.yosupo.jp/problem/eulerian_trail_undirected) (`eulerian_trail_undirected`) |  |  |
| ⬜ | [st-Numbering](https://judge.yosupo.jp/problem/st_numbering) (`st_numbering`) |  |  |
| ⬜ | [Minimum Cost b-flow](https://judge.yosupo.jp/problem/min_cost_b_flow) (`min_cost_b_flow`) |  |  |
| ⬜ | [Matching on Bipartite Graph](https://judge.yosupo.jp/problem/bipartitematching) (`bipartitematching`) |  |  |
| ⬜ | [Matching on General Graph](https://judge.yosupo.jp/problem/general_matching) (`general_matching`) |  |  |
| ⬜ | [General Weighted Matching](https://judge.yosupo.jp/problem/general_weighted_matching) (`general_weighted_matching`) |  |  |
| ⬜ | [Edge Coloring of Bipartite Graph](https://judge.yosupo.jp/problem/bipartite_edge_coloring) (`bipartite_edge_coloring`) |  |  |
| ⬜ | [Assignment Problem](https://judge.yosupo.jp/problem/assignment) (`assignment`) |  |  |
| ⬜ | [Minimum Spanning Tree](https://judge.yosupo.jp/problem/minimum_spanning_tree) (`minimum_spanning_tree`) |  |  |
| ⬜ | [Directed MST](https://judge.yosupo.jp/problem/directedmst) (`directedmst`) |  |  |
| ⬜ | [Minimum Diameter Spanning Tree](https://judge.yosupo.jp/problem/minimum_diameter_spanning_tree) (`minimum_diameter_spanning_tree`) |  |  |
| ⬜ | [Dominator Tree](https://judge.yosupo.jp/problem/dominatortree) (`dominatortree`) |  |  |
| ⬜ | [Maximum Independent Set](https://judge.yosupo.jp/problem/maximum_independent_set) (`maximum_independent_set`) |  |  |
| ⬜ | [Chromatic Number](https://judge.yosupo.jp/problem/chromatic_number) (`chromatic_number`) |  |  |
| ⬜ | [Chromatic Polynomial](https://judge.yosupo.jp/problem/chromatic_polynomial) (`chromatic_polynomial`) |  |  |
| ⬜ | [Enumerate Triangles](https://judge.yosupo.jp/problem/enumerate_triangles) (`enumerate_triangles`) |  |  |
| ⬜ | [Enumerate Cliques](https://judge.yosupo.jp/problem/enumerate_cliques) (`enumerate_cliques`) |  |  |
| ⬜ | [Counting $C _ 4$'s](https://judge.yosupo.jp/problem/counting_c4) (`counting_c4`) |  |  |
| ⬜ | [Tree Decomposition (Width 2)](https://judge.yosupo.jp/problem/tree_decomposition_width_2) (`tree_decomposition_width_2`) |  |  |
| ⬜ | [Global Minimum Cut of Dynamic Star Augmented Graph](https://judge.yosupo.jp/problem/global_minimum_cut_of_dynamic_star_augmented_graph) (`global_minimum_cut_of_dynamic_star_augmented_graph`) |  |  |
| ⬜ | [Chordal Graph Recognition](https://judge.yosupo.jp/problem/chordal_graph_recognition) (`chordal_graph_recognition`) |  |  |
| ⬜ | [Dynamic Graph Vertex Add Component Sum](https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum) (`dynamic_graph_vertex_add_component_sum`) |  |  |
| ⬜ | [Counting Eulerian Circuits](https://judge.yosupo.jp/problem/counting_eulerian_circuits) (`counting_eulerian_circuits`) |  |  |
| ⬜ | [Counting Spanning Trees (Undirected)](https://judge.yosupo.jp/problem/counting_spanning_tree_undirected) (`counting_spanning_tree_undirected`) |  |  |
| ⬜ | [Counting Spanning Trees (Directed)](https://judge.yosupo.jp/problem/counting_spanning_tree_directed) (`counting_spanning_tree_directed`) |  |  |

## Tree

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Tree Diameter](https://judge.yosupo.jp/problem/tree_diameter) (`tree_diameter`) |  |  |
| ⬜ | [Lowest Common Ancestor](https://judge.yosupo.jp/problem/lca) (`lca`) |  |  |
| ⬜ | [Jump on Tree](https://judge.yosupo.jp/problem/jump_on_tree) (`jump_on_tree`) |  |  |
| ⬜ | [Frequency Table of Tree Distance](https://judge.yosupo.jp/problem/frequency_table_of_tree_distance) (`frequency_table_of_tree_distance`) |  |  |
| ⬜ | [Rooted Tree Isomorphism Classification](https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification) (`rooted_tree_isomorphism_classification`) |  |  |
| ⬜ | [Tree Path Composite Sum](https://judge.yosupo.jp/problem/tree_path_composite_sum) (`tree_path_composite_sum`) |  |  |
| ⬜ | [Vertex Add Path Sum](https://judge.yosupo.jp/problem/vertex_add_path_sum) (`vertex_add_path_sum`) |  |  |
| ⬜ | [Vertex Set Path Composite](https://judge.yosupo.jp/problem/vertex_set_path_composite) (`vertex_set_path_composite`) |  |  |
| ⬜ | [Vertex Add Subtree Sum](https://judge.yosupo.jp/problem/vertex_add_subtree_sum) (`vertex_add_subtree_sum`) |  |  |
| ⬜ | [Vertex Add Range Contour Sum on Tree](https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree) (`vertex_add_range_contour_sum_on_tree`) |  |  |
| ⬜ | [Vertex Get Range Contour Add on Tree](https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree) (`vertex_get_range_contour_add_on_tree`) |  |  |
| ⬜ | [Point Set Tree Path Composite Sum (Fixed Root)](https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root) (`point_set_tree_path_composite_sum_fixed_root`) |  |  |
| ⬜ | [Point Set Tree Path Composite Sum](https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum) (`point_set_tree_path_composite_sum`) |  |  |
| ⬜ | [Dynamic Tree Vertex Add Path Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum) (`dynamic_tree_vertex_add_path_sum`) |  |  |
| ⬜ | [Dynamic Tree Vertex Set Path Composite](https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite) (`dynamic_tree_vertex_set_path_composite`) |  |  |
| ⬜ | [Dynamic Tree Vertex Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum) (`dynamic_tree_vertex_add_subtree_sum`) |  |  |
| ⬜ | [Dynamic Tree Subtree Add Subtree Sum](https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum) (`dynamic_tree_subtree_add_subtree_sum`) |  |  |
| ⬜ | [Cartesian Tree](https://judge.yosupo.jp/problem/cartesian_tree) (`cartesian_tree`) |  |  |
| ⬜ | [Common Interval Decomposition Tree](https://judge.yosupo.jp/problem/common_interval_decomposition_tree) (`common_interval_decomposition_tree`) |  |  |
| ⬜ | [Rooted Tree Topological Order with Minimum Inversions](https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions) (`rooted_tree_topological_order_with_minimum_inversions`) |  |  |

## Convolution

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Convolution](https://judge.yosupo.jp/problem/convolution_mod) (`convolution_mod`) |  |  |
| ⬜ | [Convolution (Mod 1,000,000,007)](https://judge.yosupo.jp/problem/convolution_mod_1000000007) (`convolution_mod_1000000007`) |  |  |
| ⬜ | [Convolution (Mod 2^64)](https://judge.yosupo.jp/problem/convolution_mod_2_64) (`convolution_mod_2_64`) |  |  |
| ⬜ | [Convolution (Large)](https://judge.yosupo.jp/problem/convolution_mod_large) (`convolution_mod_large`) |  |  |
| ⬜ | [Bitwise And Convolution](https://judge.yosupo.jp/problem/bitwise_and_convolution) (`bitwise_and_convolution`) |  |  |
| ⬜ | [Bitwise Xor Convolution](https://judge.yosupo.jp/problem/bitwise_xor_convolution) (`bitwise_xor_convolution`) |  |  |
| ⬜ | [Gcd Convolution](https://judge.yosupo.jp/problem/gcd_convolution) (`gcd_convolution`) |  |  |
| ⬜ | [Lcm Convolution](https://judge.yosupo.jp/problem/lcm_convolution) (`lcm_convolution`) |  |  |
| ⬜ | [Multidimensional Convolution (Truncated)](https://judge.yosupo.jp/problem/multivariate_convolution) (`multivariate_convolution`) |  |  |
| ⬜ | [Multidimensional Convolution (Circular)](https://judge.yosupo.jp/problem/multivariate_convolution_cyclic) (`multivariate_convolution_cyclic`) |  |  |
| ⬜ | [Convolution on the Multiplicative Monoid of $\mathbb{Z} / P\mathbb{Z}$](https://judge.yosupo.jp/problem/mul_modp_convolution) (`mul_modp_convolution`) |  |  |
| ⬜ | [Convolution on the Multiplicative Monoid of $\mathbb{Z} / 2^N\mathbb{Z}$](https://judge.yosupo.jp/problem/mul_mod2n_convolution) (`mul_mod2n_convolution`) |  |  |
| ⬜ | [Min Plus Convolution (Convex and Arbitrary)](https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary) (`min_plus_convolution_convex_arbitrary`) |  |  |
| ⬜ | [Min Plus Convolution (Convex and Convex)](https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex) (`min_plus_convolution_convex_convex`) |  |  |
| ⬜ | [Min Plus Convolution (Concave and Arbitrary)](https://judge.yosupo.jp/problem/min_plus_convolution_concave_arbitrary) (`min_plus_convolution_concave_arbitrary`) |  |  |

## Number Theory

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Enumerate Quotients](https://judge.yosupo.jp/problem/enumerate_quotients) (`enumerate_quotients`) |  |  |
| ⬜ | [Primality Test](https://judge.yosupo.jp/problem/primality_test) (`primality_test`) |  |  |
| ⬜ | [Counting Primes](https://judge.yosupo.jp/problem/counting_primes) (`counting_primes`) |  |  |
| ⬜ | [Enumerate Primes](https://judge.yosupo.jp/problem/enumerate_primes) (`enumerate_primes`) |  |  |
| ⬜ | [Factorize](https://judge.yosupo.jp/problem/factorize) (`factorize`) |  |  |
| ⬜ | [Primitive Root](https://judge.yosupo.jp/problem/primitive_root) (`primitive_root`) |  |  |
| ⬜ | [Sum of Floor of Linear](https://judge.yosupo.jp/problem/sum_of_floor_of_linear) (`sum_of_floor_of_linear`) |  |  |
| ⬜ | [Min of Mod of Linear](https://judge.yosupo.jp/problem/min_of_mod_of_linear) (`min_of_mod_of_linear`) |  |  |
| ⬜ | [Rational Approximation](https://judge.yosupo.jp/problem/rational_approximation) (`rational_approximation`) |  |  |
| ⬜ | [Stern–Brocot Tree](https://judge.yosupo.jp/problem/stern_brocot_tree) (`stern_brocot_tree`) |  |  |
| ⬜ | [Counting Square-free Integers](https://judge.yosupo.jp/problem/counting_squarefrees) (`counting_squarefrees`) |  |  |
| ⬜ | [Sum of Totient Function](https://judge.yosupo.jp/problem/sum_of_totient_function) (`sum_of_totient_function`) |  |  |
| ⬜ | [Sum of Multiplicative Function(Large)](https://judge.yosupo.jp/problem/sum_of_multiplicative_function_large) (`sum_of_multiplicative_function_large`) |  |  |
| ⬜ | [Bernoulli Number](https://judge.yosupo.jp/problem/bernoulli_number) (`bernoulli_number`) |  |  |
| ⬜ | [Sqrt Mod](https://judge.yosupo.jp/problem/sqrt_mod) (`sqrt_mod`) |  |  |
| ⬜ | [Kth Root (Mod)](https://judge.yosupo.jp/problem/kth_root_mod) (`kth_root_mod`) |  |  |
| ⬜ | [Kth Root (Integer)](https://judge.yosupo.jp/problem/kth_root_integer) (`kth_root_integer`) |  |  |
| ⬜ | [Discrete Logarithm](https://judge.yosupo.jp/problem/discrete_logarithm_mod) (`discrete_logarithm_mod`) |  |  |
| ⬜ | [Tetration Mod](https://judge.yosupo.jp/problem/tetration_mod) (`tetration_mod`) |  |  |
| ⬜ | [Gcd of Gaussian Integers](https://judge.yosupo.jp/problem/gcd_of_gaussian_integers) (`gcd_of_gaussian_integers`) |  |  |
| ⬜ | [Represent A Number As Two Square Sum](https://judge.yosupo.jp/problem/two_square_sum) (`two_square_sum`) |  |  |
| ⬜ | [Nim Product ($\mathbb{F}_{2^{64}}$)](https://judge.yosupo.jp/problem/nim_product_64) (`nim_product_64`) |  |  |

## Polynomial

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Inv of Formal Power Series](https://judge.yosupo.jp/problem/inv_of_formal_power_series) (`inv_of_formal_power_series`) |  |  |
| ⬜ | [Exp of Formal Power Series](https://judge.yosupo.jp/problem/exp_of_formal_power_series) (`exp_of_formal_power_series`) |  |  |
| ⬜ | [Log of Formal Power Series](https://judge.yosupo.jp/problem/log_of_formal_power_series) (`log_of_formal_power_series`) |  |  |
| ⬜ | [Pow of Formal Power Series](https://judge.yosupo.jp/problem/pow_of_formal_power_series) (`pow_of_formal_power_series`) |  |  |
| ⬜ | [Sqrt of Formal Power Series](https://judge.yosupo.jp/problem/sqrt_of_formal_power_series) (`sqrt_of_formal_power_series`) |  |  |
| ⬜ | [Composition of Formal Power Series](https://judge.yosupo.jp/problem/composition_of_formal_power_series) (`composition_of_formal_power_series`) |  |  |
| ⬜ | [Compositional Inverse of Formal Power Series](https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series) (`compositional_inverse_of_formal_power_series`) |  |  |
| ⬜ | [Inv of Formal Power Series (Sparse)](https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse) (`inv_of_formal_power_series_sparse`) |  |  |
| ⬜ | [Exp of Formal Power Series (Sparse)](https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse) (`exp_of_formal_power_series_sparse`) |  |  |
| ⬜ | [Log of Formal Power Series (Sparse)](https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse) (`log_of_formal_power_series_sparse`) |  |  |
| ⬜ | [Pow of Formal Power Series (Sparse)](https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse) (`pow_of_formal_power_series_sparse`) |  |  |
| ⬜ | [Sqrt of Formal Power Series (Sparse)](https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse) (`sqrt_of_formal_power_series_sparse`) |  |  |
| ⬜ | [Product of Polynomial Sequence](https://judge.yosupo.jp/problem/product_of_polynomial_sequence) (`product_of_polynomial_sequence`) |  |  |
| ⬜ | [Multipoint Evaluation](https://judge.yosupo.jp/problem/multipoint_evaluation) (`multipoint_evaluation`) |  |  |
| ⬜ | [Multipoint Evaluation (Geometric Sequence)](https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence) (`multipoint_evaluation_on_geometric_sequence`) |  |  |
| ⬜ | [Polynomial Interpolation](https://judge.yosupo.jp/problem/polynomial_interpolation) (`polynomial_interpolation`) |  |  |
| ⬜ | [Polynomial Interpolation (Geometric Sequence)](https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence) (`polynomial_interpolation_on_geometric_sequence`) |  |  |
| ⬜ | [Polynomial Taylor Shift](https://judge.yosupo.jp/problem/polynomial_taylor_shift) (`polynomial_taylor_shift`) |  |  |
| ⬜ | [Shift of Sampling Points of Polynomial](https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial) (`shift_of_sampling_points_of_polynomial`) |  |  |
| ⬜ | [Division of Polynomials](https://judge.yosupo.jp/problem/division_of_polynomials) (`division_of_polynomials`) |  |  |
| ⬜ | [Inv of Polynomials](https://judge.yosupo.jp/problem/inv_of_polynomials) (`inv_of_polynomials`) |  |  |
| ⬜ | [Factorization of Polynomial (Mod)](https://judge.yosupo.jp/problem/factorization_of_polynomials) (`factorization_of_polynomials`) |  |  |
| ⬜ | [Conversion from Monomial Basis to Newton Basis](https://judge.yosupo.jp/problem/conversion_from_monomial_basis_to_newton_basis) (`conversion_from_monomial_basis_to_newton_basis`) |  |  |
| ⬜ | [Polynomial Root Finding (Mod 998244353)](https://judge.yosupo.jp/problem/polynomial_root_finding) (`polynomial_root_finding`) |  |  |
| ⬜ | [Composition of Formal Power Series (Large)](https://judge.yosupo.jp/problem/composition_of_formal_power_series_large) (`composition_of_formal_power_series_large`) |  |  |
| ⬜ | [Compositional Inverse of Formal Power Series (Large)](https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large) (`compositional_inverse_of_formal_power_series_large`) |  |  |

## Set Power Series

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Subset Convolution](https://judge.yosupo.jp/problem/subset_convolution) (`subset_convolution`) |  |  |
| ⬜ | [Power Projection of Set Power Series](https://judge.yosupo.jp/problem/power_projection_of_set_power_series) (`power_projection_of_set_power_series`) |  |  |
| ⬜ | [Exp of Set Power Series](https://judge.yosupo.jp/problem/exp_of_set_power_series) (`exp_of_set_power_series`) |  |  |
| ⬜ | [Polynomial Composite Set Power Series](https://judge.yosupo.jp/problem/polynomial_composite_set_power_series) (`polynomial_composite_set_power_series`) |  |  |

## Enumerative Combinatorics

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Factorial](https://judge.yosupo.jp/problem/factorial) (`factorial`) |  |  |
| ⬜ | [Many Factorials](https://judge.yosupo.jp/problem/many_factorials) (`many_factorials`) |  |  |
| ⬜ | [Montmort Number](https://judge.yosupo.jp/problem/montmort_number_mod) (`montmort_number_mod`) |  |  |
| ⬜ | [Bell Number](https://judge.yosupo.jp/problem/bell_number) (`bell_number`) |  |  |
| ⬜ | [Binomial Coefficient](https://judge.yosupo.jp/problem/binomial_coefficient) (`binomial_coefficient`) |  |  |
| ⬜ | [Binomial Coefficient (Prime Mod)](https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod) (`binomial_coefficient_prime_mod`) |  |  |
| ⬜ | [$q$-Binomial Coefficient (Prime Mod)](https://judge.yosupo.jp/problem/q_binomial_coefficient_prime_mod) (`q_binomial_coefficient_prime_mod`) |  |  |
| ⬜ | [Partition Function](https://judge.yosupo.jp/problem/partition_function) (`partition_function`) |  |  |
| ⬜ | [Stirling Number of the First Kind](https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind) (`stirling_number_of_the_first_kind`) |  |  |
| ⬜ | [Stirling Number of the First Kind (Fixed K)](https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k) (`stirling_number_of_the_first_kind_fixed_k`) |  |  |
| ⬜ | [Stirling Number of the Second Kind](https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind) (`stirling_number_of_the_second_kind`) |  |  |
| ⬜ | [Stirling Number of the Second Kind (Fixed K)](https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k) (`stirling_number_of_the_second_kind_fixed_k`) |  |  |
| ⬜ | [Stirling Number of the First Kind (Small p, Large n)](https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n) (`stirling_number_of_the_first_kind_small_p_large_n`) |  |  |
| ⬜ | [Stirling Number of the Second Kind (Small p, Large n)](https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n) (`stirling_number_of_the_second_kind_small_p_large_n`) |  |  |
| ⬜ | [$\#_p$ Subset Sum](https://judge.yosupo.jp/problem/sharp_p_subset_sum) (`sharp_p_subset_sum`) |  |  |
| ⬜ | [Number of Subsequences ](https://judge.yosupo.jp/problem/number_of_subsequences) (`number_of_subsequences`) |  |  |
| ⬜ | [Number of Increasing Sequences Between Two Sequences](https://judge.yosupo.jp/problem/number_of_increasing_sequences_between_two_sequences) (`number_of_increasing_sequences_between_two_sequences`) |  |  |

## Linear Algebra

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Matrix Product](https://judge.yosupo.jp/problem/matrix_product) (`matrix_product`) |  |  |
| ⬜ | [Matrix Product (Mod 2)](https://judge.yosupo.jp/problem/matrix_product_mod_2) (`matrix_product_mod_2`) |  |  |
| ⬜ | [Pow of Matrix](https://judge.yosupo.jp/problem/pow_of_matrix) (`pow_of_matrix`) |  |  |
| ⬜ | [Determinant of Matrix](https://judge.yosupo.jp/problem/matrix_det) (`matrix_det`) |  |  |
| ⬜ | [Determinant of Matrix (Arbitrary Mod)](https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod) (`matrix_det_arbitrary_mod`) |  |  |
| ⬜ | [Determinant of Matrix (Mod 2)](https://judge.yosupo.jp/problem/matrix_det_mod_2) (`matrix_det_mod_2`) |  |  |
| ⬜ | [Determinant of Sparse Matrix](https://judge.yosupo.jp/problem/sparse_matrix_det) (`sparse_matrix_det`) |  |  |
| ⬜ | [Rank of Matrix](https://judge.yosupo.jp/problem/matrix_rank) (`matrix_rank`) |  |  |
| ⬜ | [Rank of Matrix (Mod 2)](https://judge.yosupo.jp/problem/matrix_rank_mod_2) (`matrix_rank_mod_2`) |  |  |
| ⬜ | [System of Linear Equations](https://judge.yosupo.jp/problem/system_of_linear_equations) (`system_of_linear_equations`) |  |  |
| ⬜ | [System of Linear Equations (Mod 2)](https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2) (`system_of_linear_equations_mod_2`) |  |  |
| ⬜ | [Inverse Matrix](https://judge.yosupo.jp/problem/inverse_matrix) (`inverse_matrix`) |  |  |
| ⬜ | [Inverse Matrix (Mod 2)](https://judge.yosupo.jp/problem/inverse_matrix_mod_2) (`inverse_matrix_mod_2`) |  |  |
| ⬜ | [Adjugate Matrix](https://judge.yosupo.jp/problem/adjugate_matrix) (`adjugate_matrix`) |  |  |
| ⬜ | [Characteristic Polynomial](https://judge.yosupo.jp/problem/characteristic_polynomial) (`characteristic_polynomial`) |  |  |
| ⬜ | [Hafnian of Matrix](https://judge.yosupo.jp/problem/hafnian_of_matrix) (`hafnian_of_matrix`) |  |  |
| ⬜ | [Intersection of $\mathbb{F}_{2}$ vector spaces](https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces) (`intersection_of_f2_vector_spaces`) |  |  |

## String

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Z Algorithm](https://judge.yosupo.jp/problem/zalgorithm) (`zalgorithm`) |  |  |
| ⬜ | [Enumerate Palindromes](https://judge.yosupo.jp/problem/enumerate_palindromes) (`enumerate_palindromes`) |  |  |
| ⬜ | [Suffix Array](https://judge.yosupo.jp/problem/suffixarray) (`suffixarray`) |  |  |
| ⬜ | [Number of Substrings](https://judge.yosupo.jp/problem/number_of_substrings) (`number_of_substrings`) |  |  |
| ⬜ | [Run Enumerate](https://judge.yosupo.jp/problem/runenumerate) (`runenumerate`) |  |  |
| ⬜ | [Prefix-Substring LCS](https://judge.yosupo.jp/problem/prefix_substring_lcs) (`prefix_substring_lcs`) |  |  |
| ⬜ | [Lyndon Factorization](https://judge.yosupo.jp/problem/lyndon_factorization) (`lyndon_factorization`) |  |  |
| ⬜ | [Longest Common Substring](https://judge.yosupo.jp/problem/longest_common_substring) (`longest_common_substring`) |  |  |
| ⬜ | [Eertree](https://judge.yosupo.jp/problem/eertree) (`eertree`) |  |  |
| ⬜ | [Palindromes in Deque](https://judge.yosupo.jp/problem/palindromes_in_deque) (`palindromes_in_deque`) |  |  |
| ⬜ | [Wildcard Pattern Matching](https://judge.yosupo.jp/problem/wildcard_pattern_matching) (`wildcard_pattern_matching`) |  |  |

## Geometry

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Sort Points by Argument](https://judge.yosupo.jp/problem/sort_points_by_argument) (`sort_points_by_argument`) |  |  |
| ⬜ | [Static Convex Hull](https://judge.yosupo.jp/problem/static_convex_hull) (`static_convex_hull`) |  |  |
| ⬜ | [Count Points in Triangles](https://judge.yosupo.jp/problem/count_points_in_triangle) (`count_points_in_triangle`) |  |  |
| ⬜ | [Closest Pair of Points](https://judge.yosupo.jp/problem/closest_pair) (`closest_pair`) |  |  |
| ⬜ | [Furthest Pair of Points](https://judge.yosupo.jp/problem/furthest_pair) (`furthest_pair`) |  |  |
| ⬜ | [Convex Layers](https://judge.yosupo.jp/problem/convex_layers) (`convex_layers`) |  |  |
| ⬜ | [Manhattan MST](https://judge.yosupo.jp/problem/manhattanmst) (`manhattanmst`) |  |  |
| ⬜ | [Euclidean MST](https://judge.yosupo.jp/problem/euclidean_mst) (`euclidean_mst`) |  |  |

## Big Integer

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [Addition of Big Integers](https://judge.yosupo.jp/problem/addition_of_big_integers) (`addition_of_big_integers`) |  |  |
| ⬜ | [Multiplication of Big Integers](https://judge.yosupo.jp/problem/multiplication_of_big_integers) (`multiplication_of_big_integers`) |  |  |
| ⬜ | [Division of Big Integers](https://judge.yosupo.jp/problem/division_of_big_integers) (`division_of_big_integers`) |  |  |
| ⬜ | [Addition of Hex Big Integers](https://judge.yosupo.jp/problem/addition_of_hex_big_integers) (`addition_of_hex_big_integers`) |  |  |
| ⬜ | [Multiplication of Hex Big Integers](https://judge.yosupo.jp/problem/multiplication_of_hex_big_integers) (`multiplication_of_hex_big_integers`) |  |  |
| ⬜ | [Division of Hex Big Integers](https://judge.yosupo.jp/problem/division_of_hex_big_integers) (`division_of_hex_big_integers`) |  |  |

## Other

| 状態 | 問題 | ライブラリ | verify |
| :-: | --- | --- | --- |
| ⬜ | [2 Sat](https://judge.yosupo.jp/problem/two_sat) (`two_sat`) |  |  |
| ⬜ | [Longest Increasing Subsequence](https://judge.yosupo.jp/problem/longest_increasing_subsequence) (`longest_increasing_subsequence`) |  |  |
| ⬜ | [$\sum_{i=0}^{n-1} r^i i^d$](https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial) (`sum_of_exponential_times_polynomial`) |  |  |
| ⬜ | [$\sum_{i=0}^{\infty} r^i i^d$](https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit) (`sum_of_exponential_times_polynomial_limit`) |  |  |
| ⬜ | [Find Linear Recurrence](https://judge.yosupo.jp/problem/find_linear_recurrence) (`find_linear_recurrence`) |  |  |
| ⬜ | [Kth term of Linearly Recurrent Sequence](https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence) (`kth_term_of_linearly_recurrent_sequence`) |  |  |
| ⬜ | [Consecutive Terms of Linear Recurrent Sequence](https://judge.yosupo.jp/problem/consecutive_terms_of_linear_recurrent_sequence) (`consecutive_terms_of_linear_recurrent_sequence`) |  |  |
