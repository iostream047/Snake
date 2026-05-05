#ifndef POS_H
#define POS_H

#include <cstddef> //for std::size_t
#include <functional> //for std::hash

class pos{
    friend class pos_hash_functor;
    private:
    int x;
    int y;
    bool is_invalid;

    public:
    
    pos(int x,int y);
    int get_x() const;
    int get_y() const;
    
    void inc_x();
    void dec_x();
    void inc_y();
    void dec_y();
    void invalidate();
    bool get_is_invalid() const;
    friend bool operator==(const pos& current_pos,const pos& other); //non member function with private data access 
};

// Hash functor for unordered set:
class pos_hash_functor{
    public:
    std::size_t operator()(const pos& position) const;
};

/*namespace std {
    template<>
    class hash<pos>{
        public:
        std::size_t operator()(const pos& position)const; 
    };
}*/

#endif
