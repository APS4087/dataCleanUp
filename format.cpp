#include "Format.h"

using namespace std;

// For individual instance
string Format::format2DCoordinates(int x, int y)
{
    ostringstream os;
    os << "[" << alignText(x, 4) << ", " << alignText(y, 4) << "]";
    return os.str();
}

string Format::format3DCoordinates(int x, int y, int z)
{
    ostringstream os;
    os << "[" << alignText(x, 4) << ", " << alignText(y, 4) << ", " << alignText(z, 4) << "]";
    return os.str();
}

template <typename T>
string Format::alignText(T value, const int width)
{
    ostringstream os;
    os << right << setw(width) << value;
    return os.str();
}

string Format::addSpacing(const int space)
{
    string spacing(space, ' ');
    return spacing;
}

string Format::formatDistance(double value, bool isNewLine)
{
    ostringstream os;
    os << fixed << setprecision(3) << displayWholeInfo(value);
    os << ((isNewLine) ? "\n" : "");
    return os.str();
}

double Format::displayWholeInfo(double value) { return (round(value * 1000.0) / 1000.0); }

// For individual class's Header
string Format::addHeader(const vector<string> &headers, const string distanceHeader, const bool is2D, bool isPointClass)
{
    ostringstream os;
    os << ((isPointClass) ? getPointClass(headers) : getLineClass(headers));
    os << addSpacing(4);
    os << distanceHeader << endl;
    os << ((isPointClass) ? ((is2D) ? addSeparator(31) : addSeparator(37)) : ((is2D) ? addSeparator(37) : addSeparator(49))) << endl;
    return os.str();
}

string Format::getPointClass(const vector<string> &headers)
{
    ostringstream os;
    os << addSpacing(1);
    for (int i = 0; i < headers.size(); i++)
    {
        os << alignText(headers.at(i), 4);
        if (i <= headers.size() - 2)
        {
            os << addSpacing(2);
        }
    }
    return os.str();
}

string Format::getLineClass(const vector<string> &headers)
{
    ostringstream os;
    vector<string> modifiedHeaders;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < headers.size(); j++)
        {
            modifiedHeaders.push_back(getLineHeader(i, headers.at(j)));
        }
        os << getPointClass(modifiedHeaders);
        modifiedHeaders.clear();
        if (i == 0)
        {
            os << addSpacing(4);
        }
    }
    return os.str();
}

string Format::getLineHeader(const int index, const string axis)
{
    ostringstream os;
    os << "P" << (index + 1) << "-" << axis;
    return os.str();
}

string Format::addSeparator(const int num)
{
    string dash(num, '-');
    return dash;
}