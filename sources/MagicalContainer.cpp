#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel
{
    MagicalContainer::Iterator::Iterator() {}

    MagicalContainer::MagicalContainer()
    {
        elements = vector<int>();
        ascendingIterator = AscendingIterator(*this);
        sideCrossIterator = SideCrossIterator(*this);
        primeIterator = PrimeIterator(*this);
    }

    MagicalContainer::~MagicalContainer()
    {
    }

    bool MagicalContainer::addElement(int newElement)
    {
        elements.push_back(newElement);
        return true;
    }

    bool MagicalContainer::removeElement(int element)
    {
        for (auto currElement : elements)
        {
            if (currElement == element)
            {
                elements.erase(std::find(elements.begin(), elements.end(), element));
                return true;
            }
        }
        return false;
    }

    std::vector<int> MagicalContainer::getElements() const
    {
        return this->elements;
    }

    int MagicalContainer::size() const
    {
        return elements.size();
    }

    MagicalContainer::AscendingIterator &MagicalContainer::getAscendingIterator()
    {
        return this->ascendingIterator;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::getSideCrossIterator()
    {
        return this->sideCrossIterator;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::getPrimeIterator()
    {
        return this->primeIterator;
    }

    MagicalContainer::AscendingIterator::AscendingIterator() {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : Iterator(), container(&container), sortedElements(container.elements)
    {
        this->currElement = &sortedElements[0];
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), sortedElements(other.sortedElements), currElement(other.currElement)
    {
    }

    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        sortedElements = other.sortedElements;
        container = other.container;
        return *this;
    }

    int &MagicalContainer::AscendingIterator::operator*()
    {
        return *currElement;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        ++currElement;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return false;
    }

    std::vector<int>::iterator MagicalContainer::AscendingIterator::begin()
    {
        return this->sortedElements.begin();
    }

    std::vector<int>::iterator MagicalContainer::AscendingIterator::end()
    {
        return this->sortedElements.end();
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept {return *this;}

    MagicalContainer::SideCrossIterator::SideCrossIterator()
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    {
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        return *this;
    }

    int &MagicalContainer::SideCrossIterator::operator*()
    {
        return *currElement;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return false;
    }

    std::vector<int>::iterator MagicalContainer::SideCrossIterator::begin()
    {
        return this->sortedElements.begin();
    }

    std::vector<int>::iterator MagicalContainer::SideCrossIterator::end()
    {
        return this->sortedElements.end();
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept {return *this;}


    MagicalContainer::PrimeIterator::PrimeIterator()
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    {
    }

    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        return *this;
    }

    int &MagicalContainer::PrimeIterator::operator*()
    {
        return *currElement;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return false;
    }

    std::vector<int>::iterator MagicalContainer::PrimeIterator::begin()
    {
        return this->primeElements.begin();
    }

    std::vector<int>::iterator MagicalContainer::PrimeIterator::end()
    {
        return this->primeElements.end();
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept {return *this;}


    
}