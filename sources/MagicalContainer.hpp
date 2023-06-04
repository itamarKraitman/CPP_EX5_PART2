#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <cmath>

namespace ariel
{
    using namespace std;

    class MagicalContainer
    {
        // at first, I implemented basic class named 'Iterator', but according tests, there is no need for one
    private:
        vector<int> elements;
        vector<const int *> asceindingElements;
        vector<const int *> sideCrossElements;
        vector<const int *> primeElements;

        static std::vector<const int *> sortForSideCrossIterator(vector<int> containerElements)
        {
            // vector<int> containerElements = container.elements;
            std::sort(containerElements.begin(), containerElements.end()); // Sort the vector in ascending order

            size_t start = 0;
            size_t end = containerElements.size() - 1;

            std::vector<const int *> sortedVec(containerElements.size());

            for (size_t i = 0; i < containerElements.size(); i++)
            {
                if (i % 2 == 0)
                {
                    sortedVec[i] = &containerElements[start]; // Take element from the beginning
                    start++;
                }
                else
                {
                    sortedVec[i] = &containerElements[end]; // Take element from the end
                    end--;
                }
            }

            return sortedVec;
        }

        static bool isPrime(int num)
        {

            if (num == 1)
            {
                return false;
            }

            if (num == 2)
            {
                return true;
            }

            double sqrtNum = sqrt(num);
            for (int i = 2; i <= sqrtNum; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

    public:
        MagicalContainer();
        ~MagicalContainer();
        bool addElement(int element);
        void removeElement(int element);
        std::vector<int> getElements() const;
        size_t size() const;
        bool operator==(MagicalContainer &other);
        bool operator!=(MagicalContainer &other);

        MagicalContainer(const MagicalContainer &other) = delete;
        MagicalContainer &operator=(const MagicalContainer &other) = default;
        MagicalContainer(MagicalContainer &&other) noexcept = delete;
        MagicalContainer &operator=(MagicalContainer &&other) noexcept = delete;

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t position;

        public:
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            int operator*();
            AscendingIterator &operator++();

            MagicalContainer::AscendingIterator begin();
            MagicalContainer::AscendingIterator end();

            AscendingIterator(AscendingIterator &&other) noexcept = default;
            AscendingIterator &operator=(AscendingIterator &&other) noexcept = delete;
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t position;

        public:
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            int operator*();
            SideCrossIterator &operator++();

            MagicalContainer::SideCrossIterator begin();
            MagicalContainer::SideCrossIterator end();

            SideCrossIterator(SideCrossIterator &&other) noexcept = default;
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = delete;
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t position;

        public:
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            int operator*();
            PrimeIterator &operator++();

            MagicalContainer::PrimeIterator begin();
            MagicalContainer::PrimeIterator end();

            PrimeIterator(PrimeIterator &&other) noexcept = default;
            PrimeIterator &operator=(PrimeIterator &&other) noexcept = delete;
        };
    };
}
#endif