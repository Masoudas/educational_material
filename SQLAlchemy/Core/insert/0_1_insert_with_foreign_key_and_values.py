"""
Imagine the following scenario. We want to insert values, but some are foreign keys, so we have fetch them from the database. Other values we want to enter manually, and some values have defaults. How do we do it?

The answer is that the insert statement accepts queries by itself! So, we can by hand determine what happens to each column.

t1 = sqlalchemy.Table(
        DailyMeasurementLogsTable.tableName(), self._metadata,
        sqlalchemy.Column(
            C.measurement_id, sqlalchemy.Integer, 
            sqlalchemy.ForeignKey(measurement_id_fk, ondelete="CASCADE"), 
            nullable=False),
        sqlalchemy.Column(C.date, sqlalchemy.Date, nullable=False),
        sqlalchemy.Column(
            C.log_datetime, sqlalchemy.DateTime(timezone=True), nullable=False, 
            server_default=sqlalchemy.func.now()),
        extend_existing=True
    )

Notice that measurement_id is a foreign key, date is normal. Notice that log_datetime gets a default, which is the time on the server side!

So now, consider the following insert query:

measurement_q = sqlalchemy.select(
        self.__tableDomainDef.c[C_DD.measurement_id],
    ).where(
        self.__tableDomainDef.c[C_DD.measurement] == "some_measure",
    )

id_values = [
    {C_L.measurement_id: measurement_q, C_L.date: date_i} for date_i in dates]

insert_stmt = self.__tableLogs.insert().values(id_values)
        
You see that in the insert statement, we're passing the query for measurement id, which is cool. I wonder if this query can be further optimized though!
"""
