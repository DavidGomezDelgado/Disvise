package com.disvise.disvise.advise;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import java.time.LocalDate;
import java.util.List;
import org.springframework.jdbc.core.JdbcTemplate;
@Repository
public class BbddControler {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    public void insertarAdvise(Advise advise) {
        String sql = "INSERT INTO advise (priority, magic_number, advise, date, destiny) VALUES (?, ?, ?, ?, ?)";
        jdbcTemplate.update(sql,
                advise.getPriority(),
                advise.getMagicNumber(),
                advise.getAdvise().getFunction(),
                advise.getDate().toString(),
                advise.getDestiny()
        );
    }

    public List<Advise> obtenerTodos() {
        String sql = "SELECT * FROM advise";
        return jdbcTemplate.query(sql, (rs, rowNum) -> {
            return new Advise(
                    rs.getInt("priority"),
                    rs.getLong("magic_number"),
                    new AdviseToControler(rs.getInt("advise")),
                    LocalDate.parse(rs.getString("date")),
                    rs.getString("destiny")
            );
        });
    }
}
