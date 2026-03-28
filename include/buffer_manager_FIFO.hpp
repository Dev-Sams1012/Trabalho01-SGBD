#ifndef BUFFER_MANAGER_FIFO_HPP
#define BUFFER_MANAGER_FIFO_HPP

#include "buffer_manager.hpp"

class BufferManagerFIFO : public BufferManager
{    
public:
    BufferManagerFIFO(std::string archivePath);
    
    void evict() override;
};

#endif // BUFFER_MANAGER_FIFO_HPP
