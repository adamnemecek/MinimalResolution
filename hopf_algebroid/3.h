//class for cofree comodules
template<typename algebroid, typename degree_type> 
class cofree_comodule : virtual public CoModule<algebroid, degree_type>{
public:
	//the following static functions are computing data on a cofree comodule co-generated by one element
	//the function computing the coaction on the cofree comodule
	static std::function<vectors<matrix_index, algebroid>(matrix_index)> cofree_coaction;
	//the operations on modules over algebroid
	static ModuleOp<matrix_index, algebroid> *modOpers;
	//the degree of the generators of the cofree modules
	static std::function<degree_type(matrix_index)> cofree_degree;
	 
	//the following is the data for specific cofree-comodules
	//the set of generators
	modules<degree_type> generators;
	//position of the co-generators in the set of generators of the underlying module
	std::vector<uint32_t> position_of_gens;
	//the rank of the underlying module
	int total_rank;
	 
	//get a searching index for the positions of the co-generators inside the set of module generators
	std::map<matrix_index,matrix_index> gen_pos_index();
	
	//IO operations for cofree comodules
	void save(std::iostream &writer);
	void load(std::iostream &reader);
	 
	//default constructor
	cofree_comodule();
	
	//locate in which cofree summand is a module generator lying
	unsigned findPos(unsigned startPos, unsigned endPos, unsigned n) const;
	unsigned findPos(unsigned n) const;

	//the rank function
	int rank() const;
	//the coaction function
	vectors<matrix_index, algebroid> coaction(int i) const;
	//the degree function
	degree_type degree(int i) const;

	//termwise multiply with an element in algebroid whose multiplication table is already computed
	template<typename ring>
	vectors<matrix_index,ring> multiply_using_table(unsigned i, matrix<ring> const &mult_table);
	
	//direct sum with another cofree comodule
	void direct_sum(cofree_comodule<algebroid,degree_type> const &Y);
	
	//the valuse of an null position
	static constexpr int invalid_pos = -1;
	//find if n is the position of some co-generators
	int find_index(int n);
	
	//the underlying degree
	static int underlyingDeg(degree_type);
	
	//add the degrees
	static degree_type add_degree(degree_type,degree_type);
 };
