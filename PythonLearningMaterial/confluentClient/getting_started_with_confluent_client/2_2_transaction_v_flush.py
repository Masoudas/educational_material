"""
ME: What is the difference between a transaction and a flush? The following is taken from the official documentation.

A transaction based interaction is done as follows (note that all methods raise KafkaError, where ):
    -   Call init_transaction one time:
        Initializes transactions for the producer instance.

        This function ensures any transactions initiated by previous instances of the producer with the same transactional.id are completed. If the previous instance failed with a transaction in progress the previous transaction will be aborted. This function needs to be called before any other transactional or produce functions are called when the transactional.id is configured.

        If the last transaction had begun completion (following transaction commit) but not yet finished, this function will await the previous transaction’s completion.

        When any previous transactions have been fenced this function will acquire the internal producer id and epoch, used in all future transactional messages issued by this producer instance.

        Upon successful return from this function the application has to perform at least one of the following operations within transaction.timeout.ms to avoid timing out the transaction on the broker: * produce() (et.al) * send_offsets_to_transaction() * commit_transaction() * abort_transaction()
    
    -   Call begin_transaction to start a transaction:
        Begin a new transaction. init_transactions() must have been called successfully (once) before this function is called. Any messages produced or offsets sent to a transaction, after the successful return of this function will be part of the transaction and committed or aborted atomically. Complete the transaction by calling commit_transaction() or Abort the transaction by calling abort_transaction().
    
    -   Call commit_transaction to commit the transaction:
        Commmit the current transaction. Any outstanding messages will be flushed (delivered) before actually committing the transaction. If any of the outstanding messages fail permanently the current transaction will enter the abortable error state and this function will return an abortable error, in this case the application must call abort_transaction() before attempting a new transaction with begin_transaction(). 
        
        Note: This function will block until all outstanding messages are delivered and the transaction commit request has been successfully handled by the transaction coordinator, or until the timeout expires, which ever comes first. On timeout the application may call the function again.

        Note: Will automatically call flush() to ensure all queued messages are delivered before attempting to commit the transaction. Delivery reports and other callbacks may thus be triggered from this method.

        Raises:
            KafkaError: Use exc.args[0].retriable() to check if the operation may be retried, or exc.args[0].txn_requires_abort() if the current transaction has failed and must be aborted by calling abort_transaction() and then start a new transaction with begin_transaction(). Treat any other error as a fatal error.
    
    -   Call abort_transaction to abort a transaction:
        Aborts the current transaction. This function should also be used to recover from non-fatal abortable transaction errors when KafkaError.txn_requires_abort() is True. Any outstanding messages will be purged and fail with _PURGE_INFLIGHT or _PURGE_QUEUE.

        Note: This function will block until all outstanding messages are purged and the transaction abort request has been successfully handled by the transaction coordinator, or until the timeout expires, which ever comes first. On timeout the application may call the function again.

        Note: Will automatically call purge() and flush() to ensure all queued and in-flight messages are purged before attempting to abort the transaction.

Now, consider the flush and poll method:
    -   poll(timeout): 
        Polls the producer for events and calls the corresponding callbacks (if registered).
        
        Callbacks:
            on_delivery callbacks from produce()

        Returns:
            Number of events processed (callbacks served)

    -   flush method:
        Wait for all messages in the Producer queue to be delivered. This is a convenience method that calls poll() until len() is zero or the optional timeout elapses.

So, how do we write a transaction based write?
"""
