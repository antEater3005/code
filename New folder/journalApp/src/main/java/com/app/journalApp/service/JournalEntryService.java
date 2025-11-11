package com.app.journalApp.service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.transaction.annotation.Transactional;

import com.app.journalApp.entity.JournalEntry;
import com.app.journalApp.entity.User;
import com.app.journalApp.repository.JournalEntryRepository;

import lombok.extern.slf4j.Slf4j;

@Slf4j
@Component
public class JournalEntryService {

    @Autowired
    private JournalEntryRepository journalEntryRepository;

    @Autowired
    private UserService userService;

    @Transactional
    public void saveJournalEntry(JournalEntry newEntry, String username) {
        try {
            User user = userService.getByUsername(username);
            newEntry.setDate(LocalDateTime.now());
            JournalEntry saved = journalEntryRepository.save(newEntry);
            user.getJournalEntries().add(saved); 
            userService.saveUser(user);
        } catch (Exception e) {
            log.error("Exception", e);
            throw e;
        }
    }

    public void saveJournalEntry(JournalEntry newEntry) {
        try {
            journalEntryRepository.save(newEntry);
        } catch (Exception e) {
            log.error("Exception", e);
        }
    }

    public List<JournalEntry> getAllJournals() {
        return new ArrayList<JournalEntry>(journalEntryRepository.findAll());
    }

    public Optional<JournalEntry> getJournalById(ObjectId id) {
        return journalEntryRepository.findById(id);
    }

    public boolean deleteJournal(ObjectId id, String username) {
        try {
            journalEntryRepository.deleteById(id);
            User user = userService.getByUsername(username);
            user.getJournalEntries().removeIf(x -> x.get_id().equals(id));
            userService.saveUser(user);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

}
