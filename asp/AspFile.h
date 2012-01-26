/*
 *  Copyright (C) 2012  Regents of the University of Michigan
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//////////////////////////////////////////////////////////////////////////


#ifndef __ASP_FILE_H__
#define __ASP_FILE_H__

#include "AspRecord.h"

class AspFileReader
{
public:
    AspFileReader();
    
    ~AspFileReader();
    
    /// Open the file
    /// \param  filename the file to open for reading.
    /// \return true = success; false = failure.
    bool open(const char* fileName);

    /// Close the file if it is open.
    void close();

    /// Returns whether or not the file has been opened successfully.
    /// \return true = open; false = not open.
    bool isOpen();
   
    /// Returns whether or not the end of the file has been reached.
    /// \return true = EOF; false = not eof.
    /// If the file is not open, true is returned.
    bool isEof();

    /// Get the next record without skipping empty and position records.
    /// \param rec reference to a record to populate with the next record.
    /// \return true if a record was successfully found, false if not.
    bool getNextRecord(AspRecord& rec);

    /// Get the next data record (skips over empty and position records).
    /// \param rec reference to a record to populate with the next data record.
    /// \return true if a record was successfully found, false if not.
    bool getNextDataRecord(AspRecord& rec);

    
private:
    void reset();

    IFILE myFilePtr;

    // Store the previous chromosome id/position which is necessary for getting
    // the chromid/pos for non-pos records.
    int32_t prevChrom;
    int32_t prevPos;
};


#endif
