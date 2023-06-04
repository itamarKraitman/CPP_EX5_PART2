#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel
{
    MagicalContainer::MagicalContainer() {}

    MagicalContainer::~MagicalContainer() {}

    bool MagicalContainer::addElement(int newElement)
    {
        for (auto currElement : elements)
        {
            if (newElement == currElement)
            {
                cout << "Element already exists" << endl;
                return false;
            }
        }

        // finding the correct place to store the new element in ascending order in O(n)
        auto it = std::lower_bound(elements.begin(), elements.end(), newElement);
        elements.insert(it, newElement);

        this->asceindingElements.clear();
        this->sideCrossElements.clear();
        this->primeElements.clear();

        size_t start = 0;
        size_t end = elements.size() - 1;

        for (size_t i = 0; i < elements.size(); i++) // iterating over elements in O(n) and inserting each element to the right pvector and position
        {
            this->asceindingElements.push_back(&elements[i]); // add to ascending order vector

            if (i % 2 == 0) // add to sideCross
            {
                sideCrossElements.push_back(&elements[start]); // Take element from the beginning
                start++;
            }
            else
            {
                sideCrossElements.push_back(&elements[end]); // Take element from the end
                end--;
            }

            // add to primes (isPrime is in O(n))
            if (isPrime(elements[i]))
            {
                this->primeElements.push_back(&elements[i]);
            }
        }

        return true;
    }

    void MagicalContainer::removeElement(int element)
    {
        for (auto currElement : elements)
        {
            if (currElement == element)
            {
                elements.erase(std::find(elements.begin(), elements.end(), element));
                return;
            }
        }

        throw std::runtime_error("Element does not exist");
    }

    std::vector<int> MagicalContainer::getElements() const
    {
        return this->elements;
    }

    size_t MagicalContainer::size() const
    {
        return this->elements.size();
    }

    bool MagicalContainer::operator==(MagicalContainer &other)
    {
        return (this->elements == other.elements);
    }

    bool MagicalContainer::operator!=(MagicalContainer &other)
    {
        return (this->elements != other.elements);
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : container(container), position(0)
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), position(other.position)
    {
    }

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (this->container != other.container)
        {
            throw std::runtime_error("Iterator assignment between different containers");
        }

        this->container = other.container;
        this->position = other.position;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return *(this->container.asceindingElements[position]);
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (this->position == this->end().position)
        {
            throw std::runtime_error("Iterator out of range");
        }

        ++this->position;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        if (&this->container == &other.container && this->position == other.position)
        {
            return true;
        }
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return this->position < other.position;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return this->position > other.position;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        AscendingIterator iter(this->container);
        iter.position = 0;
        return iter;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator iter(this->container);
        iter.position = this->container.size();
        return iter;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container), position(0)
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), position(other.position)
    {
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (this->container != other.container)
        {
            throw std::runtime_error("Iterator assignment between different containers");
        }

        this->container = other.container;
        this->position = other.position;
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        return *(this->container.sideCrossElements[position]);
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (this->position == this->end().position)
        {
            throw std::runtime_error("Iterator out of range");
        }
        ++this->position;
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        if (&this->container == &other.container && this->position == other.position)
        {
            return true;
        }
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return this->position < other.position;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return this->position > other.position;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        SideCrossIterator iter(this->container);
        iter.position = 0;
        return iter;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        SideCrossIterator iter(this->container);
        iter.position = this->container.size();
        return iter;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container), position(0)
    {
        // position of this iterator is for prime elements only!
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), position(other.position) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this->container != other.container)
        {
            throw std::runtime_error("Iterator assignment between different containers");
        }

        this->container = other.container;
        this->position = other.position;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        return *(this->container.primeElements[this->position]);
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (this->position == this->end().position)
        {
            throw std::runtime_error("Iterator out of range");
        }

        ++this->position;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        if (&this->container == &other.container && this->position == other.position)
        {
            return true;
        }
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return this->position < other.position;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return this->position > other.position;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        PrimeIterator iter(this->container);
        iter.position = 0;
        return iter;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        PrimeIterator iter(this->container);
        iter.position = this->container.primeElements.size();
        return iter;
    }
}