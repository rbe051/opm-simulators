/*
  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.

  Consult the COPYING file in the top-level source directory of this
  module for the precise wording of the license and the list of
  copyright holders.
*/
#ifndef ECL_MPI_SERIALIZER_HH
#define ECL_MPI_SERIALIZER_HH

#include <opm/simulators/utils/ParallelRestart.hpp>

namespace Opm {

class EclMpiSerializer {
public:
    EclMpiSerializer(Dune::MPIHelper::MPICommunicator comm) :
        m_comm(comm)
    {}

    template<class T>
    std::size_t packSize(const T& data) {
        return Mpi::packSize(data, m_comm);
    }

    template<class T>
    void pack(const T& data, std::vector<char>& buffer, int& pos) {
        Mpi::pack(data, buffer, pos, m_comm);
    }

    template<class T>
    void unpack(T& data, std::vector<char>& buffer, int& pos) {
        Mpi::unpack(data, buffer, pos, m_comm);
    }

protected:
    Dune::MPIHelper::MPICommunicator m_comm;
};

}

#endif
