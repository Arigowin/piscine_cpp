#ifndef SHOOTLIST_HPP
# define SHOOTLIST_HPP

# include <stddef.h>
# include <cassert>

# include "Shoot.hpp"

class ShootMaillon {
  public:
        ShootMaillon(Shoot shoot);
        ShootMaillon(Shoot shoot, ShootMaillon * n);
        ShootMaillon(ShootMaillon const &src);
        ~ShootMaillon(void);

        ShootMaillon &operator=(ShootMaillon const &rhs);

        Shoot           shoot;
        ShootMaillon    *next;
};

class ShootList {
    public:
        ShootList(void);
        ShootList(const ShootList &);
        ~ShootList(void);

        int     add_beginning(Shoot shoot);
        int     add_end(Shoot shoot);
        int     add_position(Shoot shoot, int position);

        void    remove_beginning();
        void    remove_end();
        void    remove_position(int position);
        void    empty(void);

        Shoot   *consult_beginning(void) const;
        Shoot   *consult_end(void) const;
        Shoot   *consult_position(int position) const;

        int     is_empty(void) const;
        int     size(void) const;

        ShootList operator=(const ShootList &);

    private:
        ShootMaillon    *tete;
        ShootMaillon    *queue;
        int             nb_maillons;
};

#endif
