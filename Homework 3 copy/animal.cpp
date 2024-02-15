// Your declarations and implementations would go here

class Animal
{
    public:
        virtual string name() const =0;
        virtual void speak() const =0;
        virtual string moveAction() const =0;
        virtual ~Animal() {};

};

class Cat : public Animal
{
    public:
        Cat(string name) : m_name(name) {};

        virtual string name() const { return m_name;}

        string moveAction() const
        {
            return "walk";
        }

        void speak() const
        {
            cout << "Meow";
        }

        virtual ~Cat()
        {
           cout << "Destroying " << m_name << " the cat" << endl;
        }
    private:
        string m_name;
};


class Pig : public Animal
{
    public:
        Pig(string name, int weight) : m_name(name), m_weight(weight) {};

        virtual string name() const { return m_name;}

        string moveAction() const
        {
            return "walk";
        }

        void speak() const
        {
            if (m_weight < 180)
                cout << "Oink";
            else
                cout << "Grunt";
        }

        virtual ~Pig()
        {
           cout << "Destroying " << m_name << " the pig" << endl;
        }
    private:
        int m_weight;
        string m_name;
};

class Duck : public Animal
{
    public:
        Duck(string name) : m_name(name) {};

        virtual string name() const { return m_name;}

        string moveAction() const
        {
            return "swim";
        }

        void speak() const
        {
            cout << "Quack";
        }

        virtual ~Duck()
        {
           cout << "Destroying " << m_name << " the duck" << endl;
        }
    private:
        string m_name;
};

