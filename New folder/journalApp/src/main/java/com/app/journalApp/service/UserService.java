package com.app.journalApp.service;

import java.util.List;
import java.util.Optional;

import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.app.journalApp.entity.User;
import com.app.journalApp.repository.UserRepository;

@Component
public class UserService {

    @Autowired
    private UserRepository userRepository;

    public User saveUser(User newUser) {
        try {
            return userRepository.save(newUser);
        } catch (Exception e) {
            // TODO: handle exception
            throw e;
        }
    }

    public Optional<User> getUserById(ObjectId id) {
        return userRepository.findById(id);
    }

    public User getByUsername(String username) {
        return userRepository.findByUsername(username).orElse(null);
    }

    // public List<User> getAllJournals() {
    // return userRepository.findAll();
    // }
    public List<User> getAllUsers() {
        return userRepository.findAll();
    }

    public boolean deleteUser(ObjectId id) {
        try {
            userRepository.deleteById(id);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

}
