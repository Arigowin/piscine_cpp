#include "ShootList.hpp"

ShootMaillon::ShootMaillon(Shoot shoot) {
    this->shoot = shoot;
    this->next = NULL;
}

ShootMaillon::ShootMaillon(Shoot shoot, ShootMaillon *n) {
    this->shoot = shoot;
    this->next = n;
}

ShootMaillon::ShootMaillon(ShootMaillon const &src) {
    *this = src;
}

ShootMaillon::~ShootMaillon(void) {}


ShootMaillon    &ShootMaillon::operator=(ShootMaillon const &rhs) {
    if (this != &rhs) {
        this->shoot = rhs.shoot;
        this->next = rhs.next;
    }
    return (*this);
}

ShootList::ShootList(void) {
    this->tete = NULL;
    this->queue = NULL;
    this->nb_maillons = 0;
}

ShootList::ShootList(const ShootList &source) {
    this->tete = NULL;
    this->queue = NULL;
    this->nb_maillons = 0;

    ShootMaillon *lecteur = source.tete;
    while (lecteur != NULL) {
        assert(this->add_end(lecteur->shoot));
        lecteur = lecteur->next;
    }
}

ShootList::~ShootList(void) {
    for (int i = 0; i < this->size(); ++i)
        delete this->consult_position(i);
}

int ShootList::add_beginning(Shoot shoot) {
    ShootMaillon *nouveau = new ShootMaillon(shoot);

    if (nouveau == NULL)
        return 0;

    nouveau->next = this->tete;
    this->tete = nouveau;
    if (this->nb_maillons == 0)
        this->queue = nouveau;
    ++this->nb_maillons;

    return 1;
}

int ShootList::add_end(Shoot shoot) {
    ShootMaillon *nouveau = new ShootMaillon(shoot);

    if (nouveau == NULL)
        return 0;
    this->queue->next = nouveau;
    this->queue = nouveau;
    if (this->nb_maillons == 0)
        this->tete = nouveau;
    ++this->nb_maillons;
    return 1;
}

int ShootList::add_position(Shoot shoot, int position) {
    if (position <= 0)
        return this->add_beginning(shoot);
    else if (position >= this->nb_maillons)
        return this->add_end(shoot);
    else {
        ShootMaillon *nouveau = new ShootMaillon(shoot);
        ShootMaillon *precedent = this->tete;
        if (nouveau == NULL)
            return 0;

        for (int i = 0; i < position - 1; ++i)
            precedent = precedent->next;

        nouveau->next = precedent->next;
        precedent->next = nouveau;
        ++this->nb_maillons;

        return 1;
    }
}

void ShootList::remove_beginning()
{
    if (this->nb_maillons > 0) {
        ShootMaillon *a_effacer = this->tete;
        this->tete = this->tete->next;
        delete a_effacer;

        --this->nb_maillons;
        if (this->nb_maillons == 0)
            this->queue = NULL;
    }
}

void ShootList::remove_end() {
    if (this->nb_maillons > 0) {
        if (this->nb_maillons > 1) {
            delete this->tete;
            this->queue = this->tete = NULL;
        }
        else {
            ShootMaillon *avant_dernier = this->tete;
            for (int i = 0; i < this->nb_maillons - 1; ++i)
                avant_dernier = avant_dernier->next;

            delete avant_dernier->next;
            avant_dernier->next = NULL;
            this->queue = avant_dernier;
        }
        --this->nb_maillons;
    }
}

void ShootList::remove_position(int position) {
    if (position >= 0 && position < this->nb_maillons) {
        if (position == 0)
            this->remove_beginning();
        else {
            ShootMaillon *precedent = this->tete;
            for (int i = 0; i < position - 1; ++i)
                precedent = precedent->next;

            ShootMaillon *a_effacer = precedent->next;
            precedent->next = a_effacer->next;
            delete a_effacer;
            --this->nb_maillons;
        }
    }
}

void ShootList::empty(void) {
    while (this->nb_maillons > 0)
        this->remove_beginning();
}

Shoot *ShootList::consult_beginning(void) const {
    if (this->nb_maillons == 0)
        return NULL;

    return &this->tete->shoot;
}

Shoot *ShootList::consult_end(void) const {
    if (this->nb_maillons == 0)
        return NULL;

    return &this->queue->shoot;
}

Shoot *ShootList::consult_position(int position) const {
    if (position < 0 && position >= this->nb_maillons)
        return NULL;

    ShootMaillon *cible = this->tete;
    for (int i = 0; i < position; ++i)
        cible = cible->next;

    return &cible->shoot;
}

int ShootList::is_empty(void) const {
    return this->nb_maillons == 0;
}

int ShootList::size(void) const {
    return this->nb_maillons;
}

ShootList ShootList::operator=(const ShootList &source) {
    if (this != &source) {
        this->empty();

        ShootMaillon *lecteur = source.tete;
        while (lecteur != NULL) {
            assert(add_end(lecteur->shoot));
            lecteur = lecteur->next;
        }
    }

    return *this;
}
